# Builds the Release version and packs it into Installer\VehicleRentalSystem_Setup.exe
# Run from anywhere:  powershell -ExecutionPolicy Bypass -File Installer\build-setup.ps1
$ErrorActionPreference = 'Stop'
$installer = $PSScriptRoot
$root = Split-Path -Parent $installer
$stage = Join-Path $installer 'staging'
$msbuild = 'C:\Program Files\Microsoft Visual Studio\18\Community\MSBuild\Current\Bin\MSBuild.exe'
$target = Join-Path $installer 'VehicleRentalSystem_Setup.exe'

# 1. build
& $msbuild (Join-Path $root 'VehicleRentalSystem.sln') /p:Configuration=Release /p:Platform=x64 /nologo /v:m '/clp:ErrorsOnly;Summary'
if ($LASTEXITCODE -ne 0) { throw 'Build failed' }

# 2. stage the files that go into the setup
if (Test-Path $stage) { Remove-Item $stage -Recurse -Force }
New-Item -ItemType Directory -Path $stage | Out-Null
$release = Join-Path $root 'x64\Release'
Copy-Item (Join-Path $release 'VehicleRentalSystem.exe') $stage
Copy-Item (Join-Path $release 'MySql.Data.dll') $stage
foreach ($f in 'Install.ps1', 'Uninstall.ps1', 'Install.cmd', 'database.sql') { Copy-Item (Join-Path $installer $f) $stage }

$redist = Get-ChildItem 'C:\Program Files\Microsoft Visual Studio\18\Community\VC\Redist\MSVC' -Recurse -Filter vc_redist.x64.exe |
          Sort-Object FullName | Select-Object -Last 1
if ($redist) { Copy-Item $redist.FullName $stage } else { Write-Warning 'vc_redist.x64.exe not found - the setup will not install the C++ runtime' }

# 3. IExpress (built into Windows) packs the staged files into one self-extracting setup
$files = Get-ChildItem $stage -File
$strings = ($files | ForEach-Object -Begin { $i = 0 } -Process { "FILE$i=`"$($_.Name)`""; $i++ }) -join "`r`n"
$list = ($files | ForEach-Object -Begin { $i = 0 } -Process { "%FILE$i%="; $i++ }) -join "`r`n"
$sed = @"
[Version]
Class=IEXPRESS
SEDVersion=3
[Options]
PackagePurpose=InstallApp
ShowInstallProgressWindow=1
HideExtractAnimation=1
UseLongFileName=1
InsideCompressed=0
CAB_FixedSize=0
CAB_ResvCodeSigning=0
RebootMode=N
InstallPrompt=
DisplayLicense=
FinishMessage=
TargetName=$target
FriendlyName=Vehicle Rental System Setup
AppLaunched=cmd /c Install.cmd
PostInstallCmd=<None>
AdminQuietInstCmd=
UserQuietInstCmd=
SourceFiles=SourceFiles
[Strings]
$strings
[SourceFiles]
SourceFiles0=$stage\
[SourceFiles0]
$list
"@
$sedPath = Join-Path $installer 'setup.sed'
Set-Content -Path $sedPath -Value $sed -Encoding ASCII
if (Test-Path $target) { Remove-Item $target -Force }
& "$env:SystemRoot\System32\iexpress.exe" /N /Q $sedPath | Out-Null

# iexpress returns before the file is finished
for ($i = 0; $i -lt 60 -and -not (Test-Path $target); $i++) { Start-Sleep -Milliseconds 500 }
Start-Sleep -Seconds 2
Remove-Item $stage -Recurse -Force
Remove-Item $sedPath -Force
if (-not (Test-Path $target)) { throw 'Setup.exe was not created' }
Write-Host "Created: $target ($([math]::Round((Get-Item $target).Length / 1MB, 1)) MB)"

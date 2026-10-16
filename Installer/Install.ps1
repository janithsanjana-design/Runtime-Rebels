# Vehicle Rental System - installer
# Copies the program, checks the prerequisites and adds shortcuts.
# The program itself creates the MySQL database the first time it starts.
param(
    [string]$InstallDir = (Join-Path $env:LOCALAPPDATA 'Programs\VehicleRentalSystem'),
    [switch]$NoLaunch,
    [switch]$NoShortcuts
)

$ErrorActionPreference = 'Stop'
$here = Split-Path -Parent $MyInvocation.MyCommand.Path

function Say($text, $color = 'White') { Write-Host $text -ForegroundColor $color }

Say '=== Vehicle Rental System - Setup ===' Cyan
Say ''

# ---------------------------------------------------------------- 1. .NET Framework 4.8
$net = Get-ItemProperty 'HKLM:\SOFTWARE\Microsoft\NET Framework Setup\NDP\v4\Full' -ErrorAction SilentlyContinue
if (-not $net -or $net.Release -lt 528040) {
    Say '[X] .NET Framework 4.8 is not installed.' Red
    Say '    Install it from https://dotnet.microsoft.com/download/dotnet-framework/net48 and run this setup again.' Red
    exit 1
}
Say '[OK] .NET Framework 4.8' Green

# ---------------------------------------------------------------- 2. Visual C++ runtime
function Test-VcRuntime {
    $vc = Get-ItemProperty 'HKLM:\SOFTWARE\Microsoft\VisualStudio\14.0\VC\Runtimes\x64' -ErrorAction SilentlyContinue
    return ($vc -and $vc.Installed -eq 1)
}
if (-not (Test-VcRuntime)) {
    $redist = Join-Path $here 'vc_redist.x64.exe'
    if (Test-Path $redist) {
        Say '... Installing Microsoft Visual C++ runtime (click Yes if Windows asks for permission)' Yellow
        $p = Start-Process -FilePath $redist -ArgumentList '/install', '/quiet', '/norestart' -Verb RunAs -Wait -PassThru
        if ($p.ExitCode -ne 0 -and $p.ExitCode -ne 3010) {
            Say "[X] The Visual C++ runtime setup failed (code $($p.ExitCode))." Red
            exit 1
        }
    } else {
        Say '[X] Microsoft Visual C++ Redistributable 2015-2022 (x64) is missing.' Red
        Say '    Install it from https://aka.ms/vs/17/release/vc_redist.x64.exe and run this setup again.' Red
        exit 1
    }
}
Say '[OK] Visual C++ runtime' Green

# ---------------------------------------------------------------- 3. MySQL (information only)
$mysql = Get-Service -ErrorAction SilentlyContinue | Where-Object { $_.Name -like 'MySQL*' -or $_.Name -like 'MariaDB*' } | Select-Object -First 1
if ($mysql) {
    if ($mysql.Status -eq 'Running') { Say "[OK] MySQL service '$($mysql.Name)' is running" Green }
    else { Say "[!] MySQL service '$($mysql.Name)' is installed but not running. Start it in Windows Services." Yellow }
} else {
    Say '[!] MySQL Server was not found on this PC.' Yellow
    Say '    Install MySQL Server 8 (https://dev.mysql.com/downloads/installer/) before using the program,' Yellow
    Say '    or type the address of another MySQL server when the program asks for the connection.' Yellow
}

# ---------------------------------------------------------------- 4. copy the program
Say ''
Say "Installing to: $InstallDir"
New-Item -ItemType Directory -Force -Path $InstallDir | Out-Null
foreach ($file in 'VehicleRentalSystem.exe', 'MySql.Data.dll', 'Uninstall.ps1', 'database.sql') {
    Copy-Item -LiteralPath (Join-Path $here $file) -Destination $InstallDir -Force
}
Say '[OK] Files copied' Green

# ---------------------------------------------------------------- 5. shortcuts + Apps & features entry
$exe = Join-Path $InstallDir 'VehicleRentalSystem.exe'
if (-not $NoShortcuts) {
    $shell = New-Object -ComObject WScript.Shell
    $places = @([Environment]::GetFolderPath('Desktop'), [Environment]::GetFolderPath('Programs'))
    foreach ($folder in $places) {
        $lnk = $shell.CreateShortcut((Join-Path $folder 'Vehicle Rental System.lnk'))
        $lnk.TargetPath = $exe
        $lnk.WorkingDirectory = $InstallDir
        $lnk.Description = 'Vehicle Rental System'
        $lnk.IconLocation = "$exe,0"
        $lnk.Save()
    }
    Say '[OK] Desktop and Start menu shortcuts created' Green

    $key = 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Uninstall\VehicleRentalSystem'
    New-Item -Path $key -Force | Out-Null
    Set-ItemProperty $key DisplayName 'Vehicle Rental System'
    Set-ItemProperty $key Publisher 'ICT1306 OOP project'
    Set-ItemProperty $key InstallLocation $InstallDir
    Set-ItemProperty $key DisplayIcon $exe
    Set-ItemProperty $key UninstallString ('powershell.exe -NoProfile -ExecutionPolicy Bypass -File "' + (Join-Path $InstallDir 'Uninstall.ps1') + '"')
    Set-ItemProperty $key NoModify 1
    Set-ItemProperty $key NoRepair 1
}

Say ''
Say 'Setup finished.' Cyan
Say 'On the first start the program asks for the MySQL server, user and password,' White
Say 'then creates the database and tables by itself.' White

if (-not $NoLaunch) {
    Start-Process -FilePath $exe -WorkingDirectory $InstallDir
}

# Vehicle Rental System - uninstaller
# Removes the program and shortcuts. The MySQL database and dbconfig.ini are NOT deleted.
param(
    [string]$InstallDir = (Split-Path -Parent $MyInvocation.MyCommand.Path),
    [switch]$Quiet
)

$ErrorActionPreference = 'SilentlyContinue'

if (-not $Quiet) {
    Add-Type -AssemblyName System.Windows.Forms
    $answer = [System.Windows.Forms.MessageBox]::Show(
        "Remove Vehicle Rental System from this PC?`r`n`r`nYour MySQL data is kept.",
        'Uninstall', 'YesNo', 'Question')
    if ($answer -ne 'Yes') { exit 0 }
}

Get-Process VehicleRentalSystem | Stop-Process -Force

foreach ($folder in @([Environment]::GetFolderPath('Desktop'), [Environment]::GetFolderPath('Programs'))) {
    Remove-Item -LiteralPath (Join-Path $folder 'Vehicle Rental System.lnk') -Force
}
Remove-Item -Path 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Uninstall\VehicleRentalSystem' -Recurse -Force

# this script lives in the folder it deletes, so delete the folder from a helper process
$cmd = 'ping 127.0.0.1 -n 3 > nul & rmdir /s /q "' + $InstallDir + '"'
Start-Process -FilePath cmd.exe -ArgumentList '/c', $cmd -WindowStyle Hidden

if (-not $Quiet) {
    [System.Windows.Forms.MessageBox]::Show('Vehicle Rental System was removed.', 'Uninstall') | Out-Null
}

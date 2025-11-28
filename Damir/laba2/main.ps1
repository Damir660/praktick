Write-Host "Running PowerShell script: $($MyInvocation.MyCommand.Name)"

function Show-MainMenu {
    do {
        Clear-Host
        Write-Host "Main Menu:"
        Write-Host "1. Select mode (edit/program)"
        Write-Host "2. Exit"
        $choice = Read-Host "Enter your choice"
        
        switch ($choice) {
            '1' { Invoke-ModeSelection }
            '2' { return }
            default { Write-Host "Invalid option!"; Start-Sleep -Seconds 1 }
        }
    } while ($true)
}

function Invoke-ModeSelection {
    $result = & .\read_pwd.exe 20
    switch ($result) {
        0 { Show-EditMenu }
        1 { Show-ProgramMenu }
        2 { Write-Host "Wrong password!"; Start-Sleep -Seconds 2 }
        3 { Write-Host "Timeout occurred!"; Start-Sleep -Seconds 2 }
    }
}

function Show-EditMenu {
    do {
        Clear-Host
        Write-Host "Edit Menu:"
        Write-Host "a) Notepad"
        Write-Host "b) Word"
        Write-Host "c) Exit"
        
        $choice = & .\choice.exe a b c
        switch ($choice) {
            1 { Start-Process notepad.exe }
            2 { Start-Process "C:\Program Files\Microsoft Office\Office16\WINWORD.EXE" }
            3 { return }
        }
        if ($choice -ne 3) { Start-Sleep -Seconds 2 }
    } while ($choice -ne 3)
}

function Show-ProgramMenu {
    do {
        Clear-Host
        Write-Host "Program Menu:"
        Write-Host "a) Visual Studio"
        Write-Host "b) Calculator"
        Write-Host "c) Exit"
        
        $choice = & .\choice.exe a b c
        switch ($choice) {
            1 { Start-Process "C:\Program Files\Microsoft Visual Studio 9.0\Common7\IDE\devenv.exe" }
            2 { Start-Process calc.exe }
            3 { return }
        }
        if ($choice -ne 3) { Start-Sleep -Seconds 2 }
    } while ($choice -ne 3)
}

Show-MainMenu

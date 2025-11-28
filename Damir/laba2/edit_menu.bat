@echo off
:edit_menu
echo.
echo Edit Menu:
echo a) Notepad
echo b) Word
echo c) Exit
choice.c.exe a b c
if errorlevel 3 goto exit
if errorlevel 2 start "" "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Word"
if errorlevel 1 start notepad.exe
goto edit_menu
:exit
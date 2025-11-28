@echo off
:program_menu
echo.
echo Program Menu:
echo a) Visual Studio
echo b) Calculator
echo c) Exit

choice.c.exe a b c
set p=%errorlevel%

if %p%==3 goto exit
if %p%==2 start calc.exe
if %p%==1 start "" "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe"

goto program_menu

:exit
exit /b

@echo off
echo Running batch file: %0

:mainmenu
echo.
echo Main Menu:
echo 1. Select mode (edit/program)
echo 2. Exit
choice /c 12 /n
if errorlevel 2 goto exit
if errorlevel 1 goto mode_select

:mode_select
echo.
read_pwd.exe 20
set error_code=%errorlevel%
if %error_code% equ 4 goto timeout
if %error_code% equ 3 goto wrong_pwd
if %error_code% equ 2 goto program_menu
if %error_code% equ 1 goto edit_menu


:timeout
echo Timeout occurred!
goto mainmenu

:wrong_pwd
echo Wrong password!
goto mainmenu

:edit_menu
call edit_menu.bat
goto mainmenu

:program_menu
call program_menu.bat
goto mainmenu

:exit
echo Exiting...

call init.cmd

@REM ::强制获取管理员运行权限
@REM %1 mshta vbscript:CreateObject("Shell.Application").ShellExecute("cmd.exe","/c %~s0 ::","","runas",1)(window.close)&&exit

setlocal EnableDelayedExpansion
color 0E
:loop
@echo off

echo.
echo "Let choose your action"
echo "If you input 0, you can clear all the data."
echo "If you input 1, you can choose the numbers of data files."
echo "If you input 2, you can exit the program."
set /p input=Input the order:
if "%input%" == "0" (
    start /b Clear.exe
    echo Clear all the data.
    goto loop
)
if "%input%" == "1" (
    set /p kk=Please input the numbers of data files:

    echo You choose to make %kk% data files.
    for /L %%A in (1,1,!kk!) do (
        echo Now is file%%A
        call main.exe
        )
    echo All the data files have been processed.
    goto loop
)
if "%input%" == "2" (
    echo Exit the program.
    exit
)

call Run.cmd

color 0E
:loop
@echo off
setlocal EnableDelayedExpansion

echo.
echo "Let choose your action"
echo "If you input 0, you can clear all the data."
echo "If you input 1, you can choose the numbers of data files."
echo "If you input 2, you can exit the program."
set /p input=Input the order:
if "%input%" == "0" (
    call Clear.exe
    echo Clear all the data.
    goto loop
)
if "%input%" == "1" (
    set /p kk=Input the number of data files:

    for /L %%A in (1,1,%kk%) do (
        echo Now is file%%A 
        call main.exe 
        timeout /t 1
        )
    echo All the data files have been processed.
    goto loop
)
if "%input%" == "2" (
    echo Exit the program.
    exit
)

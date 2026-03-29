@echo off
echo Compiling...
g++ *.cpp -o brawl_game.exe

if %errorlevel% neq 0 (
    echo.
    echo [ERROR] Compilation failed!
    pause
    exit /b %errorlevel%
)

echo Success! Running the game...
echo.
brawl_game.exe
pause
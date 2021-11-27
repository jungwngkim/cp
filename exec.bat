@echo off

echo [INFO] compiling '%1.cpp'
g++ .\src\%1.cpp -o .\temp\out -std=gnu++14 -Wall

if %errorlevel% == 0 (
    echo [INFO] compile success

    echo [INFO] executing '%1.cpp'
    .\temp\out.exe
    
    del .\temp\out.exe
) else (
    echo [ERROR] complie error
)

@echo off

set TEMPLATE=.\content\template.cpp
set FILE=.\src\%1.cpp

if exist %FILE% (
    echo [WARN] '%1.cpp' exists in '.\src'
) else (
    echo [INFO] creating '%1.cpp' in '.\src'
    copy %TEMPLATE% %FILE%
)

echo [INFO] opening '%1.cpp'
code %FILE%

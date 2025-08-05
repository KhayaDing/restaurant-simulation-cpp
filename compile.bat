@echo off
echo Restaurant Simulation Program Compiler
echo =====================================

REM Try different compilers
echo Attempting to compile with available compilers...

REM Try g++
where g++ >nul 2>&1
if %errorlevel% == 0 (
    echo Found g++ compiler
    g++ -std=c++11 -Wall -Wextra -O2 -o restaurant_simulation.exe restaurant_simulation.cpp
    if %errorlevel% == 0 (
        echo Compilation successful with g++
        echo Run with: restaurant_simulation.exe
        goto :end
    )
)

REM Try clang++
where clang++ >nul 2>&1
if %errorlevel% == 0 (
    echo Found clang++ compiler
    clang++ -std=c++11 -Wall -Wextra -O2 -o restaurant_simulation.exe restaurant_simulation.cpp
    if %errorlevel% == 0 (
        echo Compilation successful with clang++
        echo Run with: restaurant_simulation.exe
        goto :end
    )
)

REM Try MSVC cl
where cl >nul 2>&1
if %errorlevel% == 0 (
    echo Found MSVC compiler
    cl /std:c++11 /EHsc restaurant_simulation.cpp /Fe:restaurant_simulation.exe
    if %errorlevel% == 0 (
        echo Compilation successful with MSVC
        echo Run with: restaurant_simulation.exe
        goto :end
    )
)

echo No compatible C++ compiler found.
echo Please install one of the following:
echo - MinGW-w64 (for g++)
echo - LLVM (for clang++)
echo - Visual Studio Build Tools (for MSVC)
echo.
echo Or use an online C++ compiler like:
echo - https://www.onlinegdb.com/
echo - https://replit.com/
echo - https://godbolt.org/

:end
pause 
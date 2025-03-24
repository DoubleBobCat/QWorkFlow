@echo off
mkdir build 2>nul
cd build || exit /b
cmake .. -G "MinGW Makefiles" || exit /b
cmake --build . || exit /b
Test.exe
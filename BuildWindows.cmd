@echo off
setlocal
cd /d "%~dp0"

cmake.exe -B Windows -G "Visual Studio 17 2022" -A x64 &&^
cmake.exe --build Windows --config Release ||^
pause

endlocal

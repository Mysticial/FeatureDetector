@echo off
setlocal
cd /d "%~dp0"

wsl cmake -B Linux -G "Ninja Multi-Config" %* ^&^& ^
cmake --build Linux --config Release ||^
pause

endlocal

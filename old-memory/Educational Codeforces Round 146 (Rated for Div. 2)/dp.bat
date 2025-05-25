@echo off
:loop  
g++ data.cpp -o data.exe
g++ std.cpp -o std.exe
g++ xx.cpp -o xx.exe
    data.exe > data.in
    std.exe < data.in > std.out
    xx.exe < data.in > my.out
    fc my.out std.out
if not errorlevel 1 goto loop  
pause
goto loop
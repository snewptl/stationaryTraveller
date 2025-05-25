@echo off
g++ data.cpp -o data.exe
g++ xx.cpp -o xx.exe
g++ baoli.cpp -o baoli.exe
:loop  
    data.exe > data.in
    xx.exe < data.in > std.out
    baoli.exe < data.in > my.out
    fc my.out std.out
if not errorlevel 1 goto loop  
pause
goto loop
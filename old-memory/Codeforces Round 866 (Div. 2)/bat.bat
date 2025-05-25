@echo off
g++ data.cpp -o data.exe
g++ std.cpp -o std.exe
g++ B.cpp -o B.exe
:loop  
    data.exe > data.in
    std.exe < data.in > std.out
    B.exe < data.in > my.out
    fc my.out std.out
if not errorlevel 1 goto loop  
pause
goto loop
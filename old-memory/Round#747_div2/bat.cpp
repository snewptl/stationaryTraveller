//对拍
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    long s,t;
    while(1){
        system("g++ gen.cpp -o gen.exe");
        system("g++ my.cpp -o my.exe");
        system("g++ std.cpp -o std.exe");
        system("cls");
        do{
            system("gen.exe > gen.in");
            s=clock();
            system("my.exe < gen.in > my.out");
            t=clock();
            system("std.exe < gen.in > std.out");
            if(system("fc my.out std.out > nul"))break;
            else printf("AC time: %lldms\n",t-s);
        }while(1);
        printf("WA time: %ldms\n",t-s);
        system("fc my.out std.out");
        system("pause > nul");
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int manx=1e6+10;
int main(){
    freopen("data.in","w",stdout);
    srand(time(NULL));
    printf("3 12345\n");
    for(int i=1;i<=12345;i++)printf("%d",rand()%2);
    return 0;
}
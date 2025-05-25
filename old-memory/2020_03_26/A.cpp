#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int a,b;
        scanf("%d%d",&a,&b);
        int c=a/b,d=a%b;
        int x=b-d;
        x=x%b;
        printf("%d\n",x);
    }
    return 0;
}
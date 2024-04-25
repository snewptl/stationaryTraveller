#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        int x=1,y=1;
        while(k>0){
            k-=x;
            y++;
            x++;
        }
        x=y-1+k;
        for(int i=1;i<=n-y;i++)printf("a");
        printf("b");
        for(int i=n-y+2;i<=n-x;i++)printf("a");
        printf("b");
        for(int i=n-x+2;i<=n;i++)printf("a");
        printf("\n");
    }
    return 0;   
}
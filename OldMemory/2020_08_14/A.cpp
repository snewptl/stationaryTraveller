#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
int n,a[maxn],flag;
int main(){
    int n;
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);flag=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=3;i<=n;i++){
            if(a[1]+a[2]>a[i]){
                printf("%d %d %d\n",i-2,i-1,i);
                flag=1;break;
            }
        }
        if(!flag)printf("-1\n");
    }

    return 0;
}
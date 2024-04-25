#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],b[maxn*2],c[maxn*2];
int fron[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n/2;i++){
            int x=min(a[i],a[n+1-i]);
            int y=max(a[i],a[n+1-i]);
            b[0]+=2;b[x+1]+=-1;
            b[x+y]+=-1,b[x+y+1]+=1;
            b[y+k+1]+=1;
        }
        c[0]=b[0];
        for(int i=1;i<=k*2;i++){
            c[i]=c[i-1]+b[i];
        }
        int sum=2*n;
        for(int i=1;i<=2*k;i++){
            sum=min(sum,c[i]);
        }
        printf("%d\n",sum);
    }

    return 0;
}
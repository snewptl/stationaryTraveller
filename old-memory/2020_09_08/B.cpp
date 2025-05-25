#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,mx,p,k;
int a[maxn],vis[maxn];
int chu[maxn];
bool cmp(int a,int b){
    return a>b;
}
int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}
int get_gcd(int p,int k){
    int m=0;
    for(int x=1;x<=n;x++){
        if(vis[x]||x==p)continue;
        int g=gcd(a[p],k);
        if(g>m)m=g;
    }
    return m;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);mx=0,p=0;
        memset(vis,0,sizeof(vis));
        memset(chu,0,sizeof(chu));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(mx<a[i]){
                mx=a[i];p=i;
            }
        }
        vis[p]=1,k=mx;printf("%d ",mx);
        for(int i=2;i<=n;i++){
            int m=0;
            for(int j=1;j<=n;j++){
                if(vis[j])continue;
                int g=gcd(a[j],k);
                if(g>m){
                    m=g,p=j;
                }
                
            }printf("%d ",a[p]);
            k=m,vis[p]=1;
        }
        printf("\n");
    }

    return 0;
}
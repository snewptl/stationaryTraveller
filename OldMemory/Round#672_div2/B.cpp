#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n;
int a[maxn],b[maxn],vis[50];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)b[i]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            while(a[i]){
                b[i]++;a[i]/=2;
            }
            vis[b[i]]++;
        }
        ll ans=0;
        for(int i=1;i<=40;i++){
            if(vis[i])ans+=1LL*vis[i]*(vis[i]-1)/2;
        }
        printf("%lld\n",ans);
    }


    return 0;
}
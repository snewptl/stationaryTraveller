#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int cnt=1,h[maxn];
struct Edge{
    int v,next;
}e[maxn*2];
void add(int u,int v){
    e[cnt].v=v;
    e[cnt].next=h[u];
    h[u]=cnt++;
}
int n,a,b,da,db,ans;
int dep[maxn],maxl[maxn];
void dfs(int u,int fa){
    for(int i=h[u];i;i=e[i].next){
        int v=e[i].v;
        if(v==fa)continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        ans=max(ans,maxl[u]+maxl[v]+1);
        maxl[u]=max(maxl[u],maxl[v]+1);
    }
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        memset(e,0,sizeof(e));
        memset(h,0,sizeof(h));
        memset(dep,0,sizeof(dep));
        cnt=1;
        memset(maxl,0,sizeof(maxl));ans=0;
        scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);add(y,x);
        }
        dfs(a,0);
        if(da>=db)printf("Alice\n");
        else if(dep[b]<=da)printf("Alice\n");
        else {
            if(ans>da*2&&da*2<db)printf("Bob\n");
            else printf("Alice\n");
        }
    }

    return 0;
}
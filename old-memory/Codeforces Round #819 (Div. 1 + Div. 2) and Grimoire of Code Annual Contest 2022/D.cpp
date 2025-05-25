#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
vector<pii>e[maxn];
int n,m;
int vis[maxn],sgn[maxn],tot;
int fa[2][maxn];
int find(int sgn,int x){
    return fa[sgn][x]==x?x:fa[sgn][x]=find(sgn,fa[sgn][x]);
}
void init(){
    tot=0;
    for(int i=1;i<=n;i++){
        e[i].clear();
        vis[i]=0;
        fa[0][i]=fa[1][i]=i;
    }
    for(int i=1;i<=m;i++)sgn[i]=0;
}
void dfs(int u,int pre,int pa){
    vis[u]=++tot;
    for(auto it:e[u]){
        int v=it.first,idx=it.second;
        if(vis[v]>vis[u]||pa==v)continue;
        else if(vis[v]){
            for(int t=0;t<2;t++){
                if(find(t,u)!=find(t,v)){
                    fa[t][find(t,v)]=find(t,u);
                    sgn[idx]=t;
                    break;
                }
            }
        }
        else {
            sgn[idx]=sgn[pre]^1;
            fa[sgn[idx]][find(sgn[idx],v)]=find(sgn[idx],u);
            dfs(v,idx,u);
        }
    }
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&m);
        init();
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].push_back({v,i});
            e[v].push_back({u,i});
        }
        dfs(1,0,0);
        for(int i=1;i<=m;i++)printf("%d",sgn[i]);
        puts("");
	}


	return 0;
}
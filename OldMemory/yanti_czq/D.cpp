#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=3e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,col[maxn],cnt[maxn],fa[maxn],in[maxn];
vector<int>e[maxn];
int dfn[maxn],tot;
void dfs(int u,int p){
	dfn[u]=++tot;
	fa[u]=p;
	for(auto v:e[u]){
		if(v==p)continue;
		if(dfn[v]){
			if(col[u]==col[v]&&dfn[v]<dfn[u])cnt[u]++;
			continue;
		}
		col[v]=col[u]^1;
		dfs(v,u);
	}
}
void init(){
	tot=0;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<=n;i++)dfn[i]=cnt[i]=in[i]=0;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
			in[u]++,in[v]++;
		}
		for(int i=1;i<=n;i++){
			if(dfn[i]||in[i]<2)continue;
			col[i]=0;
			dfs(i,0);
		}
		for(int u=1;u<=n;u++){
			if(cnt[u]==2){
				for(int i=u;i;i=fa[i]){
					if(cnt[i])col[i]^=1;
					else {
						cnt[i]++;
						break;
					}

				}
			}
		}
		for(int i=1;i<=n;i++)printf("%d",col[i]);
		puts("");
	}


	return 0;
}
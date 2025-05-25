#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int fa[maxn],dis[maxn];
int n,m,q;
vector<pii>e[maxn],g[maxn];
int vis[maxn][50];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void bfs(int x){
	queue<int>q;
	q.push(x);
	dis[x]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto it:e[u]){
			int v=it.first,w=it.second;
			int temp=w;
			if(dis[u])temp&=dis[u];
			if(temp==1||find(v)==find(u))continue;
			else{
				dis[v]=temp;
				q.push(v);
				fa[find(v)]=find(u);
			}
		}
	}
}
void solve(int cur){
	
	
	for(int i=1;i<=n;i++){
		if(!vis[i][cur]){
			queue<int>q;
			int tot=0;
			q.push(i);
			vis[i][cur]=++tot;
			while(!q.empty()){
				int u=q.front();q.pop();
				for(auto it:g[u]){
					int v=it.first,w=it.second;
					if(vis[v][cur])continue;
					if(w&(1<<cur)){
						q.push(v);
						vis[v][cur]=tot;
					}
				}				
			}

		}
	}
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int temp=(1<<30)-1;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			temp&=w;
			if(w%2){
				e[u].push_back({v,w});
				e[v].push_back({u,w});
			}
			else {
				if(find(u)!=find(v))
					fa[find(u)]=find(v);
			}
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		for(int i=1;i<=n;i++){
			bfs(i);
		}
		for(int j=0;j<30;j++){
			solve(j);
		}
		scanf("%d",&q);
		while(q--){
			int u,v;
			scanf("%d%d",&u,&v);
			int flag=0;
			for(int i=0;i<30;i++)if(vis[u][i]==vis[i][i])flag=1;
			if(temp||flag)puts("0");
			else if(find(u)==find(v))puts("1");
			else puts("2");
		}
	}


	return 0;
}
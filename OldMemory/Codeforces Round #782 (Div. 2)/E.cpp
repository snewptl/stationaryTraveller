#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int fa[maxn][50],book[maxn];
int n,m,q;
vector<pii>e[maxn],g[maxn];
int vis[maxn][50];
int find(int x,int j){
	return fa[x][j]==x?x:fa[x][j]=find(fa[x][j],j);
}
void bfs(int x,int j){
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto it:e[u]){
			int v=it.first,w=it.second;
			if(!(w&(1<<j))||find(v,j)==find(u,j))continue;
			else{
				q.push(v);
				fa[find(v,j)][j]=find(u,j);
			}
		}
	}
}
void solve(int cur){
	
	int tot=0;
	for(int i=1;i<=n;i++){
		if(!vis[i][cur]){
			queue<int>q;
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
		for(int i=1;i<=n;i++)
			for(int j=0;j<30;j++)fa[i][j]=i;
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			temp&=w;
			if(w%2){
				e[u].push_back({v,w});
				e[v].push_back({u,w});
			}
			else {
				for(int j=0;j<30;j++)
					fa[find(u,j)][j]=find(v,j);
			}
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		for(int j=1;j<30;j++)
			for(int i=1;i<=n;i++){
				for(auto it:g[i]){
					if(it.second%2==0){
						bfs(i,j);
						break;
					}
				}
				
			}
		for(int i=1;i<=n;i++){
			for(auto it:g[i]){
				for(int j=1;j<30;j++)
				if(find(it.first,j)==find(i,j)){
					book[i]=1;
					// if(i==1)printf("#%d %d\n",i,it.first);
					break;
				}
			}			
		}
		for(int j=0;j<30;j++){
			solve(j);
		}
		scanf("%d",&q);
		while(q--){
			int u,v;
			scanf("%d%d",&u,&v);
			int flag=0;
			if(temp)flag=1;
			for(int i=0;i<30;i++)if(vis[u][i]==vis[v][i])flag=1;
			if(flag)puts("0");
			else if(book[u])puts("1");
			else puts("2");
		}
	}


	return 0;
}
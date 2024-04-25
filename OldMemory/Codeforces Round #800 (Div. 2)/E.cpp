#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,dis[maxn],vis[maxn],deg[maxn];
vector<int>e[maxn];
void dij(int s){
	priority_queue<pii,vector<pii>,greater<pii>>q;
	memset(dis,0x3f,sizeof(dis));
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		auto p=q.top();
		q.pop();
		if(vis[p.second])continue;
		vis[p.second]=1;
		for(auto v:e[p.second]){
			deg[v]--;
			if(dis[v]>=dis[p.second]+deg[v]+1){
				dis[v]=dis[p.second]+deg[v]+1;
				q.push({dis[v],v});
			}
		}
	}


}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[v].push_back(u);
			deg[u]++;
		}
		dij(n);
		printf("%d\n",dis[1]);
	}


	return 0;
}
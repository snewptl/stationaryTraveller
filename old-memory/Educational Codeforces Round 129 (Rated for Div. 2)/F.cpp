#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=5e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
ll ans;
vector<pii>e[maxn];
int cnt[maxn],sz[maxn],dep[maxn],top[maxn];
vector<int>vec[maxn],st[maxn];
void dfs(int u,int p){
	sz[u]=1;
	for(auto it:e[u]){
		int v=it.first,w=it.second;
		if(v==p)continue;
		int temp=top[w];
		if(top[w]!=1){
			vec[top[w]].push_back(v);
		}
		else {
			st[w].push_back(v);
		}
		top[w]=v;
		dfs(v,u);
		top[w]=temp;
		sz[u]+=sz[v];
	}
	if(u!=1){
		ll x=0,y=sz[u];
		for(auto v:vec[u]){
			x+=cnt[v];
			y-=sz[v];
		}
		ans+=x*y;
		cnt[u]=y;		
	}
	else {
		for(int w=1;w<=n;w++){
			ll x=0,y=sz[u];
			for(auto v:st[w]){
				x+=cnt[v];
				y-=sz[v];
			}
			ans+=x*y;
		}
	}

}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++)top[i]=1;
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
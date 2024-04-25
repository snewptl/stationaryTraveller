#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
struct Edge{
	int next,v,w;
}e[maxn<<1];
int cnt=1,h[maxn],in[maxn];
void add(int u,int v,int w){
	e[cnt].v=v; 
	e[cnt].w=w;
	e[cnt].next=h[u];
	h[u]=cnt++;
}
int n;
ll ans;
int size[maxn];
ll lim[maxn],dp[maxn];
void dfs1(int u,int p){
	size[u]=1;
	for(int i=h[u];i;i=e[i].next){
		int v=e[i].v;
		ll w=e[i].w;
		if(v==p)continue;
		dfs1(v,u);
		size[u]+=size[v];
		lim[u]+=(size[v]==1?w:min(w,lim[v]));
	}
}
void dfs2(int u,int p){
	for(int i=h[u];i;i=e[i].next){
		int v=e[i].v;
		ll w=e[i].w;
		if(v==p)continue;
		dp[v]=min(dp[u]-(size[v]==1?w:min(lim[v],w)),w)+lim[v];
		dfs2(v,u);
	}
}
void clear_all(){
	cnt=1;ans=0;
	for(int i=1;i<=n;i++)h[i]=0;
	for(int i=1;i<=n;i++)lim[i]=0;
	for(int i=1;i<=n;i++)in[i]=0;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);add(v,u,w);
			in[u]++,in[v]++;
		}
		int p=1;
		for(int i=1;i<=n;i++)if(in[i]!=1)p=i;
		dfs1(p,0);
		dp[p]=lim[p];
		dfs2(p,0);
		for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
		printf("%lld\n",ans);
		clear_all();
	}
	return 0;
}
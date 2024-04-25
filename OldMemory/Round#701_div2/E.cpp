#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,mxdep,a[maxn];
int cnt=1,h[maxn];
struct Edge{
	int v,next;
}e[maxn<<1];
void add(int u,int v){
	e[cnt].v=v;
	e[cnt].next=h[u];
	h[u]=cnt++;
}
int dep[maxn],pa[maxn];
ll dp[maxn];
vector<int>lev[maxn];
void dfs(int u,int p){
	lev[dep[u]].push_back(u);
	for(int i=h[u];i;i=e[i].next){
		int v=e[i].v;
		if(p==v)continue;
		dep[v]=dep[u]+1;
		pa[v]=u;
		mxdep=max(mxdep,dep[v]);
		dfs(v,u);
	}
}
void solve(){
	ll ans=0;
	for(int i=1;i<=mxdep;i++){
		ll mx1=-1e18,mx2=-1e18;
		for(auto x:lev[i-1]){
			for(int j=h[x];j;j=e[j].next){
				int v=e[j].v;
				if(dep[v]<dep[x])continue;
				mx1=max(dp[x]+a[v],mx1);
				mx2=max(dp[x]-a[v],mx2);
			}
		}
		for(auto x:lev[i])
			dp[x]=max(mx1-a[x],mx2+a[x]);

		int mx=0,mn=1e9;
		for(auto x:lev[i]){
			mx=max(mx,a[x]);
			mn=min(mn,a[x]);
		}
		for(auto x:lev[i]){
			dp[x]=max(max(dp[pa[x]]+mx-a[x],dp[pa[x]]+a[x]-mn),dp[x]);
			ans=max(dp[x],ans);
			// printf("%d %d\n",x,dp[x]);
		}
	}

	printf("%lld\n",ans);
}
void init(){
	cnt=1;mxdep=0;
	for(int i=1;i<=n;i++)h[i]=0,dep[i]=0,dp[i]=0;
	for(int i=1;i<=n;i++)lev[i].clear();
}
int main(){
    int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=2;i<=n;i++){
			int v;scanf("%d",&v);
			add(i,v);add(v,i);
		}
		for(int i=2;i<=n;i++)
			scanf("%d",&a[i]);
		dfs(1,0);
		solve();init();
	}
    return 0;
}
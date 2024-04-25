#include<bits/stdc++.h>
using namespace std;
typedef double db;
const int maxn=1e4+5;
const double eps=0.00000000001;
int n;
vector<int>e[maxn];
int kill[maxn],esc[maxn];
struct Node{
	double rt,fa,cons;//ratio : dp[1]  dp[father]  const
	Node(){
		rt=fa=cons=0.0;
	}
}dp[maxn];
int sz[maxn];
void dfs(int u,int p){
	sz[u]=1;
	double idx=0.0;
	double temp=1.0-(kill[u]+esc[u])/100.0;
	for(auto v:e[u]){
		if(v==p)continue;
		sz[u]++;
		dfs(v,u);
		idx+=dp[v].fa;
	}	
	if(u==1)return;
	idx=1.0-idx*temp/sz[u];
	for(auto v:e[u]){
		if(v==p)continue;
		dp[u].cons+=temp/sz[u]*(dp[v].cons+1.0)/idx;
		dp[u].rt+=temp/idx/sz[u]*dp[v].rt;
	}
	dp[u].fa=temp/sz[u]/idx;
	dp[u].cons+=temp/sz[u]/idx;
	dp[u].rt+=kill[u]/100.0/idx;
}
int main(){
	int T,t=0;scanf("%d",&T);
	while(++t<=T){
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			scanf("%d%d",&kill[i],&esc[i]);
		}
		dfs(1,0);sz[1]--;
		double ans=0.0,idx=1.0;
		for(auto v:e[1]){
			idx-=(dp[v].rt+dp[v].fa)/sz[1];
			ans+=(dp[v].cons+1.0)/sz[1];
		}
		if(idx<=eps)printf("Case %d: impossible\n",t);
		else printf("Case %d: %.6lf\n",t,ans/idx);
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=n;i++){
			dp[i].fa=dp[i].cons=dp[i].rt=0.0;
		}
	}

	return 0;
}
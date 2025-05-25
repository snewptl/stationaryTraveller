#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
vector<int>e[maxn];
int n,ans[maxn];
int sz[maxn],dp[maxn][2];
int mx[maxn];
void update(int u,int k){
	if(k>dp[u][0])dp[u][1]=dp[u][0],dp[u][0]=k;
	else if(k==dp[u][0])dp[u][1]=k;
	else if(k>dp[u][1])dp[u][1]=k;	
}
void dfs(int u,int p){
	sz[u]=1;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==p)continue;
		dfs(v,u);
		sz[u]+=sz[v];
		if(mx[u]<sz[v])
			mx[u]=sz[v];
		if(sz[v]<=n/2)update(u,sz[v]);
		else update(u,dp[v][0]);
	}
	
}
void dfs2(int u,int p){
	if(mx[u]<=n/2&&n-sz[u]<=n/2)ans[u]=1;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==p)continue;
		if(sz[v]>n/2){
			if(sz[v]-dp[v][0]<=n/2)ans[u]=1;
		}
		int k0=dp[v][0],k1=dp[v][1];
		if(n-sz[v]<=n/2)update(v,n-sz[v]);
		else if(sz[v]==dp[u][0]||dp[u][0]==dp[v][0])update(v,dp[u][1]);
		else update(v,dp[u][0]);
		// printf("%d %d\n",v,dp[v][1]);
		dfs2(v,u);
		dp[v][0]=k0,dp[v][1]=k1;
		if(n-sz[v]>n/2){
			int k;
			if(sz[v]==dp[u][0]||dp[v][0]==dp[u][0])k=dp[u][1];
			else k=dp[u][0];
			if(n-sz[v]-k<=n/2)ans[v]=1;
		}	
	}

}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);dfs2(1,0);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
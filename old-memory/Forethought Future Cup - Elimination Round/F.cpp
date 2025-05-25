#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll mod=998244353;
int n;
vector<int>e[maxn],rk[maxn];
int dep[maxn],sz[maxn];
ll dp[maxn][2];
ll maxdep,sum=1;
struct Tree{
	ll tag,val;
}t[maxn<<2];
void init(){
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			ans[i]+=(i+1)*dp[j];
			dp[j+1]+=dp[j];
		}
	}
}

void dfs(int u,int p){
	rk[dep[u]].push_back(u);
	maxdep=max(maxdep,dep[u]);
	for(auto v:e[u]){
		if(v==p)continue;
		sz[u]++;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
int main(){
    scanf("%d",&n);init();
	for(int i=2;i<=n;i++){
		int x;scanf("%d",&x);
		e[i].push_back(x);
		e[x].push_back(i);
	}
	dfs(1,0);
	if(maxdep)for(auto u:rk[maxdep-1]){
		sum*=(ans[sz[u]+1][0]+ans[sz[u]]);
		sum%=mod;
	}
	for(int d=maxdep-2;d>=0;d--){
		ll temp=1;
		for(auto u:rk[d]){
			sum*=(ans[sz[u]+])
		}
	}

    return 0;
}
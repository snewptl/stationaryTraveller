#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
vector<int>e[maxn];
int n;
ll l[maxn],r[maxn];
ll dp[maxn][2];
void dfs(int u,int p){
	for(auto v:e[u]){
		if(v==p)continue;
		dfs(v,u);
		dp[u][0]+=max(dp[v][0]+abs(l[u]-l[v]),dp[v][1]+abs(r[v]-l[u]));
		dp[u][1]+=max(dp[v][0]+abs(r[u]-l[v]),dp[v][1]+abs(r[v]-r[u]));
	}
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld",&l[i],&r[i]);
			dp[i][0]=dp[i][1]=0;
			e[i].clear();
		}
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1,0);
		printf("%lld\n",max(dp[1][0],dp[1][1]));
    }


    return 0;
}
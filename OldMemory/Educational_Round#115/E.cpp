#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e3+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,q;
ll dp[maxn][maxn][2];
int vis[maxn][maxn];
ll ans;
ll dfs(int x,int y,int sgn){
	if(dp[x][y][sgn])return dp[x][y][sgn];
	dp[x][y][sgn]=1;
	if(!sgn){
		if(y<m)dp[x][y][sgn]+=dfs(x,y+1,sgn^1);
	}
	else {
		if(x<n)dp[x][y][sgn]+=dfs(x+1,y,sgn^1);
	}
	return dp[x][y][sgn];
}
void update(int x,int y,int sgn){
	if(!vis[x][y]){
		ans-=dp[x][y][0]+dp[x][y][1]-1;
		dp[x][y][0]=dp[x][y][1]=1;
		if(y<m)dp[x][y][0]+=dp[x][y+1][1];
		if(x<n)dp[x][y][1]+=dp[x+1][y][0];
		ans+=dp[x][y][0]+dp[x][y][1]-1;		
	}
	if(!sgn){
		if(x>1)update(x-1,y,1);
	}
	else {
		if(y>1)update(x,y-1,0);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	dfs(1,1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dfs(i,j,0);
			dfs(i,j,1);
			ans+=dp[i][j][0]+dp[i][j][1]-1;
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(vis[x][y]){
			dp[x][y][0]=dp[x][y][1]=1;
			if(y<m)dp[x][y][0]+=dp[x][y+1][1];
			if(x<n)dp[x][y][1]+=dp[x+1][y][0];	
			ans+=dp[x][y][0]+dp[x][y][1]-1;		
			if(y>1)update(x,y-1,0);
			if(x>1)update(x-1,y,1);
			vis[x][y]=0;
		}
		else {
			ans-=dp[x][y][0]+dp[x][y][1]-1;
			dp[x][y][0]=dp[x][y][1]=0;
			if(y>1)update(x,y-1,0);
			if(x>1)update(x-1,y,1);
			vis[x][y]=1;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=5e4+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,ans;
void mul(int &x){
	if(x>=mod)x-=mod;
	else if(x<0)x+=mod;
}
vector<int>e[maxn],to[maxn];
int dp[maxn][1050];
int lowbit(int x){
	return x&(-x);
}
void init(){
	for(int i=0;i<(1<<10);i++){
		if(i)to[i].push_back(i);
		for(int j=0;j<10;j++){
			if((1<<j)&i)continue;
			int cur=1<<j;
			for(auto k:e[j])
				if((1<<k)&i)cur^=1<<k;
			if(lowbit(cur)==(1<<j))to[i].push_back(cur);
		}
	}
}
void solve(){
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<10);j++){
			for(auto k:to[j]){
				dp[i][k]+=dp[i-1][j];
				mul(dp[i][k]);
			}
		}
	}
	for(int i=0;i<(1<<10);i++){
		ans+=dp[n][i];
		mul(ans);
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	init();
	solve();


	return 0;
}
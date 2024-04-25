#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
vector<int>e[maxn];
int n;
ll x,y;
int dep[maxn];
int cnt[maxn];
ll dp[maxn][3];
void dfs1(int u,int p){
	cnt[dep[u]]++;
	for(int v:e[u]){
		if(v==p)continue;
		dep[v]=dep[u]+1;
		dfs1(v,u);
	}
}
void dfs2(int u,int p){
	ll sum=0;
	ll mn1=1e18,mn2=1e18;
	for(int v:e[u]){
		if(v==p)continue;
		dfs2(v,u);
		sum+=min(dp[v][0],min(dp[v][1],dp[v][2]))+y;
		ll temp=min(dp[v][1],dp[v][0])+x-(min(dp[v][0],min(dp[v][1],dp[v][2]))+y);
		if(temp<mn1)mn2=mn1,mn1=temp;
		else if(temp==mn1)mn2=temp;
		else if(temp<mn2)mn2=temp;
	}
	dp[u][0]=sum;
	if(e[u].size()){
		dp[u][1]=mn1+sum;
		if(e[u].size()>=2)dp[u][2]=mn2+mn1+sum;
	}
}
int main(){
	scanf("%d%lld%lld",&n,&x,&y);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dep[1]=1;dfs1(1,0);
	if(!cnt[3]||(cnt[3]==n-2)){
		if(x<y){
			if(n>=3)printf("%lld\n",x*2+y*(n-3));
			else printf("%lld\n",x*(n-1));
		}
		else {
			printf("%lld\n",(n-2)*y+x);
		}
	}
	else {
		if(x>=y)printf("%lld\n",y*(n-1));
		else {
			memset(dp,0x3f,sizeof(dp));
			dfs2(1,0);
			printf("%lld\n",min(min(dp[1][0],dp[1][1]),dp[1][2]));
		}
	}
    return 0;
}
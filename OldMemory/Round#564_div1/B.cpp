#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll mod=998244353;
vector<int>e[maxn];
ll ans=1;
int n;
ll fac[maxn],mi[maxn];
void dfs(int u,int p,int dep){
	int sum=0;
	for(int v:e[u]){
		if(v==p)continue;
		sum++;
		dfs(v,u,dep+1);
	}
	if(dep)ans*=sum+1,ans%=mod;
	ans*=fac[sum],ans%=mod;
}
int main(){
    scanf("%d",&n);
	mi[0]=fac[0]=1;
	for(int i=1;i<=n;i++){
		mi[i]=mi[i-1]*2,mi[i]%=mod;
		fac[i]=fac[i-1]*i,fac[i]%=mod;
	}
	ans=n;
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);e[v].push_back(u);
	}
	dfs(1,0,0);
	printf("%lld",ans);
    return 0;
}
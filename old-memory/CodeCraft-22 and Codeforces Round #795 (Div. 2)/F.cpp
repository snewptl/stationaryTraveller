#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=1e9+7;
const double eps=1e-10;
int n,k;
vector<int>e[maxn];
ll sz[maxn],cal[maxn],fac[maxn];
ll ans;
void dfs(int u,int p){
	ll sum=0;
	sz[u]=1;
	for(auto v:e[u]){
		if(v==p)continue;
		dfs(v,u);
		sz[u]+=sz[v];
		sum+=cal[sz[v]];
		sum%=mod;
	}
	if(p)sum+=cal[n-sz[u]],sum%=mod;
	for(auto v:e[u]){
		int cnt=n-sz[v];
		if(v==p)cnt=sz[u];
		ans+=(cal[cnt]-sum+cal[n-cnt]+mod)%mod*cnt%mod*(n-cnt)%mod;
		ans%=mod;
	}
	ans+=(cal[n]-sum+mod)%mod*n%mod;
	ans=(ans+mod)%mod;
}
ll qpow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)res*=x,res%=mod;
		x*=x,x%=mod;
		y>>=1;
	}
	return res;
}
void init(){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	for(int i=k;i<=n;i++){
		cal[i]=fac[i]*qpow(fac[i-k],mod-2)%mod*qpow(fac[k],mod-2)%mod;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	init();
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
vector<pair<int,pll>>e[maxn];
int n;
ll a[maxn];
ll qpow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)res*=x,res%=mod;
		y>>=1;
		x*=x,x%=mod;
	}
	return res;
}
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int vis[maxn];
int rt;
ll ans;
ll dfs(int u,int fa){
	ll res=0;
	for(auto x:e[u]){
		int v=x.first;
		if(fa==v)continue;
		pll p=x.second;
		if(!res)res=dfs(v,u)*p.second;
		else res=gcd(res,dfs(v,u)*p.second);
	}
	if(!res)return 1;
	else return res;
}
void get_i(int u,ll d,ll cur,int fa){
	int sgn=1;
	for(auto x:e[u]){
		
		int v=x.first;
		if(fa==v)continue;
		sgn=0;
		pll p=x.second;
		get_i(v,d,(cur*p.second)%mod,u);
	}	
	if(sgn){
		a[rt]*=qpow(d,mod-2),a[rt]%=mod;
		a[rt]*=cur,a[rt]%=mod;
	}
}
void get_ans(int u,int fa){
	for(auto x:e[u]){
		int v=x.first;
		if(fa==v)continue;
		pll p=x.second;
		a[v]=a[u]*p.first%mod*qpow(p.second,mod-2)%mod;
		get_ans(v,u);
	}		
}
void init(){
	for(int i=1;i<=n;i++)vis[i]=0,a[i]=0;
	for(int i=1;i<=n;i++)e[i].clear();
	ans=0;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<n;i++){
			int x,y,u,v;
			scanf("%d%d%d%d",&u,&v,&x,&y);
			ll curd=gcd(x,y);
			x/=curd,y/=curd;
			pll p={x,y};
			e[v].push_back({u,p});
			p={y,x};  
			e[u].push_back({v,p});
		}
		rt=1;
		ll d=dfs(rt,0);
		a[rt]=d;
		cout<<d<<endl;
		get_i(rt,d,1,0);
		get_ans(rt,0);		
		for(int i=1;i<=n;i++){
			ans+=a[i],ans%=mod;
		}
		printf("%lld\n",ans%mod);

	}


	return 0;
}
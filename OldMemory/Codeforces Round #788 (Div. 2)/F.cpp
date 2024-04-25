#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e3+5;
const ll mod=1e9+7;
const double eps=1e-10;
int n;
ll z,l,r;
ll dp[70][maxn];
int a[70];
ll fac[maxn],cs[maxn];
ll qpow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)res*=x,res%=mod;
		x*=x,x%=mod;
		y/=2;
	}
	return res;
}
ll cal(int x,int y){
	return fac[x]*qpow(fac[y],mod-2)%mod*qpow(fac[x-y],mod-2)%mod;
}
ll get_ans(int dep,int cur){
	if(dp[dep][cur]!=-1)return dp[dep][cur];
	ll res=0;
	int st=(z>>dep)&1;
	for(int i=st;i<=min(n,cur);i+=2){
		int temp;
		if(dep){
			temp=2*(cur-i)+a[dep-1];
			if(temp>=2*n)temp=2*n;
			res+=cs[i]*get_ans(dep-1,temp)%mod;
		}
		else {
			res+=cs[i];
		}
		res%=mod;
	}
	return dp[dep][cur]=res;
}
ll solve(ll x){
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<=60;i++){
		a[i]=x%2;
		x/=2;
	}
	return get_ans(60,a[60]);
}
void init(){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	for(int i=0;i<=n;i++)cs[i]=cal(n,i);
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%lld%lld%lld",&n,&l,&r,&z);
		init();
		printf("%lld\n",(solve(r)-solve(l-1)+mod)%mod);
	}


	return 0;
}
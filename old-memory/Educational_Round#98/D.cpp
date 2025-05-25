#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const long long mod=998244353;
ll n;
ll dp[maxn];
ll quick_pow(ll x,ll y,ll mod){
	ll ans=1;
	while(y){
		if(y&1)ans*=x,ans%=mod;
		x*=x,x%=mod;
		y>>=1;
	}
	return ans;
}
int main(){
	scanf("%lld",&n);
	ll sum1=0,sum2=1;
	for(int i=1;i<=n;i++){
		if(i%2)dp[i]=sum2;
		else dp[i]=sum1;
		if(i%2)sum1+=dp[i];
		else sum2+=dp[i];
		dp[i]%=mod;
		sum1%=mod;
		sum2%=mod;
	}
	ll k=quick_pow(2,n,mod);
	printf("%lld",dp[n]*quick_pow(k,mod-2,mod)%mod);

    return 0;
}
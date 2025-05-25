#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
ll dp[70],op[70],fac[70],inv[70];
int n;
ll qpow(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1)res*=x,res%=mod;
        x*=x,x%=mod;
        y/=2;
    }
    return res;
}
int main(){
    fac[0]=1;
    for(int i=1;i<=60;i++)fac[i]=fac[i-1]*i%mod;
    inv[60]=qpow(fac[60],mod-2);
    for(int i=59;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        dp[2]=1;
        for(int i=4;i<=n;i+=2){
            dp[i]=op[i-2]+fac[i-1]*inv[i/2-1]%mod*inv[i-i/2]%mod;
            dp[i]%=mod;
            op[i]=fac[i]*inv[i/2]%mod*inv[i/2]%mod-1-dp[i]+mod;
            op[i]%=mod;
        }
        ll tot=fac[n]*inv[n/2]%mod*inv[n/2]%mod;
        printf("%lld %lld %lld\n",dp[n],op[n],1);
	}


	return 0;
}
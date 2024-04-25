#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=1e9+7;
const double eps=1e-10;
ll bin[maxn],a[maxn];
ll fac[maxn],inv[maxn];
ll qpow(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1)res*=x,res%=mod;
        x*=x,x%=mod;
        y>>=1;
    }
    return res;
}
int main(){
    bin[0]=1;
    for(int i=1;i<maxn;i++)bin[i]=bin[i-1]*2,bin[i]%=mod;
    fac[0]=1;
    for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;
    int n,k;
    scanf("%d%d",&n,&k);
    inv[n+k]=qpow(fac[n+k],mod-2);
    for(int i=n+k-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    if(n<=k)printf("%lld\n",bin[n]);
    else printf("%lld %lld %lld\n",inv[k]*fac[n]%mod,fac[k],fac[n+k]*inv[n]%mod*inv[k]%mod);


	return 0;
}
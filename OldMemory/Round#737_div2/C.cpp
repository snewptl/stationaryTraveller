#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=2e5+10;
int n,k;
ll mi[maxn];
ll qpow(ll x,ll m){
	ll ans=1;
	while(m){
		if(m&1)ans*=x,ans%=mod;
		x*=x,x%=mod;
		m/=2;
	}
	return ans;
}
int main(){
    int T;scanf("%d",&T);
	mi[0]=1;
	for(int i=1;i<=2e5;i++)mi[i]=mi[i-1]*2,mi[i]%=mod;
    while(T--){
		scanf("%d%d",&n,&k);
		ll idx;
		if(n%2){
			idx=mi[n-1]+1;
		}
		else idx=mi[n-1]-1;
		ll temp=1,ans=0;
       for(int i=k-1;i>=0;i--){
		   if(n%2==0){
			   ans+=temp*qpow(2,1ll*i*n),ans%=mod;
		   }
		   temp*=idx,temp%=mod;
	   } 
	   ans+=temp,ans%=mod;
	   printf("%lld\n",ans);
    }


    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=1e9+7;
const double eps=1e-10;
int n,a[maxn];
ll qpow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)res*=x,res%=mod;
		x*=x,x%=mod;
		y/=2;
	}
	return res;
}
int mi[65];
int sum[65];
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			int temp=0;
			while(a[i]%2==0){
				a[i]/=2;temp++;
			}
			mi[temp]++;
		}
		sum[0]=mi[0];
		// for(int i=0;i<=60;i++)if(mi[i])printf("%d\n",mi[i]);
		for(int i=1;i<60;i++)sum[i]=sum[i-1]+mi[i];
		ll ans=qpow(2,n)-qpow(2,n-mi[0]);
		ans%=mod;
		ll pre=1;
		for(int i=1;i<59;i++){
			pre*=qpow(2,max(0,mi[i]-1));
			pre%=mod;
			ans+=(qpow(2,mi[i+1])-qpow(2,max(0,mi[i+1]-1)))%mod*(pre-1)%mod*qpow(2,n-sum[i+1])%mod;
			ans%=mod;
			// printf("%d %lld %lld\n",i,pre,ans);
		}
		ans+=pre-1;
		ans=(ans+mod*2)%mod;
		printf("%lld\n",ans);
	}


	return 0;
}
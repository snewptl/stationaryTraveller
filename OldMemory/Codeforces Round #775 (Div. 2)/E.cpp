#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
int s[maxn],t[maxn];
int cnt[maxn];
ll idx,sum,ans;
ll fac[maxn],ifac[maxn];
map<int,int>mp;
ll q_pow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1)ans*=x,ans%=mod;
		y>>=1;
		x*=x,x%=mod;
	}
	return ans;
}
void init(){
	fac[0]=0;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	ifac[n]=q_pow(fac[n],mod-2);
	for(int i=n-1;i>=0;i--){
		ifac[i]=ifac[i+1]*(i+1)%mod;
	}
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&s[i]);
			cnt[s[i]]++;
			sum+=cnt[s[i]];
		}
		idx=fac[sum];
		for(int i=1;i<maxn;i++){
			if(!cnt[i])continue;
			mp[cnt[i]]++;
			idx=(idx*ifac[cnt[i]])%mod;
		}
		for(int i=1;i<=m;i++)scanf("%d",&t[i]);
		for(int i=1;i<=min(m,n);i++){
			for(auto p:mp){
				if(p.first<=t[i])continue;
				int k=p.second;
				ll temp=idx*ifac[sum]%mod*fac[sum-1]%mod*ifac[k-1]%mod*fac[k]%mod;
				ans=(ans+temp)%mod;
			}
			if(cnt[t[i]]){
				idx=idx*ifac[sum]%mod*fac[sum-1]%mod*ifac[cnt[t[i]]-1]%mod*fac[cnt[t[i]]]%mod;
				mp[cnt[t[i]]]--;
				mp[cnt[t[i]-1]]++;
				cnt[t[i]]--;
				sum--;
			
			}
			else break;
		}
		printf("%lld\n",ans);
	}


	return 0;
}
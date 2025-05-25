#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e5+5;
int n;
ll a[maxn];
int cnt[4];
ll ans=1;
map<ll,int>mp;
ll mi[maxn];
ll quick_p(ll x,int t){
	ll ans=1;
	while(t){
		if(t&1)ans*=x,ans%=mod;
		t>>=1;x*=x,x%=mod;
	}
	return ans;
}
int main(){
	ll sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
		mp[a[i]]++;
	}
	mi[0]=1;
	for(int i=1;i<=n;i++)mi[i]=mi[i-1]*i,mi[i]%=mod;
	if(sum%n)printf("0\n");
	else {
		sum/=n;
		int p=0;
		for(int i=1;i<=n;i++){
			if(a[i]<sum)cnt[1]++;
			if(a[i]>sum)cnt[3]++;
			if(a[i]==sum)cnt[2]++;
		}
		if(cnt[1]==1||cnt[3]==1){
			ans=mi[n];
		}
		else {
			ans*=mi[cnt[1]],ans%=mod;
			ans*=mi[cnt[3]],ans%=mod;
			if(cnt[1]&&cnt[3])ans*=2,ans%=mod;
			for(int i=cnt[1]+cnt[3]+1;i<=n;i++){
				ans*=i,ans%=mod;
			}			
		}
		for(auto x:mp){
			ll temp=x.second;
			if(!temp)continue;
			ans*=quick_p(mi[temp],mod-2),ans%=mod;
		}
		printf("%lld\n",ans);
	}


	return 0;
}
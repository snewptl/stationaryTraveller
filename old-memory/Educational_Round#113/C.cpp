#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=2e5+10;
const ll mod=998244353;
int n;
pii a[maxn];
ll ans;
ll fac[maxn];
bool check(){
	for(int i=1;i<n;i++){
		if(a[i+1].first-a[i].first>1)return false;
	}
	return true;
}
int main(){
	fac[0]=1;
	for(int i=1;i<=2e5;i++){
		fac[i]=fac[i-1]*i;
		fac[i]%=mod;
	}
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++){
			int x;scanf("%d",&x);
			a[i]={x,i};
		}
		sort(a+1,a+n+1);
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(a[i].first==a[n].first)cnt1++;
		}
		for(int i=1;i<=n;i++){
			if(a[i].first==a[n-cnt1].first)cnt2++;
		}
		if(cnt1>1)ans=fac[n];
		else if(cnt2&&a[n].first-a[n-cnt1].first>1)ans=0;
		else {
			ans=(fac[cnt1+cnt2]-fac[cnt2]+mod)%mod;
			for(int i=cnt1+cnt2+1;i<=n;i++){
				ans*=i;ans%=mod;
			}
		}
		printf("%lld\n",ans);
	}


    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
map<int,int>mp1,mp2;
int n;
int a[maxn],b[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		mp1.clear(),mp2.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i],&b[i]);
			mp1[a[i]]++,mp2[b[i]]++;
		}
		ll tot=1ll*n*(n-1)*(n-2)/6;
		ll ans1=0,ans2=0,ans3=0;
		ll sum1=0,sum2=0,sum3=0;
		for(auto x:mp1){
			ll cnt=x.second;
			if(cnt>=2)ans1+=cnt*(cnt-1)/2*(n-cnt);
			if(cnt>=3)ans1+=cnt*(cnt-1)*(cnt-2)/6;
		}
		sum1=tot-ans1;
		for(auto x:mp2){
			ll cnt=x.second;
			if(cnt>=2)ans2+=cnt*(cnt-1)/2*(n-cnt);
			if(cnt>=3)ans2+=cnt*(cnt-1)*(cnt-2)/6;
		}
		sum2=tot-ans2;
		for(int i=1;i<=n;i++){
			ll cnt1=mp1[a[i]],cnt2=mp2[b[i]];
			ans3+=(cnt1-1)*(cnt2-1);
		}
		sum3=tot-ans1-ans2+ans3;
		printf("%lld\n",sum1+sum2-sum3);

	}


	return 0;
}
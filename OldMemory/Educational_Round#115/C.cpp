#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
unordered_map<int,int>mp;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
ll tot;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		tot=0;
		mp.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			tot+=a[i];
			mp[a[i]]++;
		}
		sort(a+1,a+n+1);
		ll d=gcd(n,tot);
		ll dn=n/d,up=tot/d;
		ll ans=0;
		a[0]=-1;
		if(dn<=2){
			if(dn==1)up*=2;
			for(int i=1;i<=n;i++){
				if(a[i]==a[i-1])continue;
				if(up-a[i]<a[i])break;
				int x=up-a[i];
				if(x==a[i])ans+=1ll*mp[a[i]]*(mp[a[i]]-1)/2;
				else ans+=1ll*mp[a[i]]*mp[x];
			}
		}
		printf("%lld\n",ans);
	}


	return 0;
}
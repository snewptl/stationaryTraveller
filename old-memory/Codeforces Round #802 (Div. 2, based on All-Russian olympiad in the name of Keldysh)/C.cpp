#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
ll a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		ll mn=a[n];
		ll ans=0;
		for(int i=n-1;i>=1;i--){
			if(a[i]<a[i+1]){
				ans+=a[i+1]-a[i];
				mn-=(a[i+1]-a[i]);
			}
		}
		if(mn<0)ans+=abs(mn),a[1]+=abs(mn);
		ans+=a[1];
		printf("%lld\n",ans);
	}


	return 0;
}
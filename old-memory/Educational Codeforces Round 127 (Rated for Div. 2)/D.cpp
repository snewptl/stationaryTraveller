#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,x,a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		int mn=1e9,mx=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			mn=min(mn,a[i]);
			mx=max(mx,a[i]);
		}
		ll ans=0;
		for(int i=1;i<n;i++){
			ans+=abs(a[i+1]-a[i]);
		}
		if(a[1]>a[n])swap(a[1],a[n]);
		if(1<mn)ans+=min(a[1]-1,(mn-1)*2);
		if(x>mx)ans+=min(x-a[n],(x-mx)*2);
		printf("%lld\n",ans);
	}


	return 0;
}
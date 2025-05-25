#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
ll a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		ll sum=0;
		for(int i=1;i<n;i++)sum+=a[i];
		int ans=max(1ll,a[n]-sum);
		if(a[n]==0)ans=0;
		printf("%d\n",ans);
	}


	return 0;
}
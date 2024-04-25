#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=3e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
ll m;
ll fac[maxn];
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&m);
		fac[0]=1;
		for(int i=1;i<=n;i++){
			fac[i]=fac[i-1]*i%m;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans+=1ll*(n-i+1)*(n-i+1)%m*fac[i]%m*fac[n-i]%m;
			ans%=m;
		}
		printf("%lld\n",ans);
	}


	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
ll fac[maxn];
int main(){
	int T=1;scanf("%d",&T);
	fac[0]=1;
	for(int i=1;i<=1e3;i++)fac[i]=fac[i-1]*i,fac[i]%=mod;
	while(T--){
		scanf("%d",&n);
		ll ans=0;
		if(n%2==0){
			ans=fac[n/2]*fac[n/2]%mod;
		}
		printf("%lld\n",ans);
	}


	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
ll p2[60];
ll n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		int cnt=0;
		scanf("%lld",&n);
		ll pn=n;
		while(n%2==0)cnt++,n/=2;
		if(n==1)puts("-1");
		else {
			ll k=(1ll<<(cnt+1));
			if((k-1)/2<pn/k)
				printf("%lld\n",k);
			else {
				k=n;
				printf("%lld\n",k);
			}
		}
	}


	return 0;
}
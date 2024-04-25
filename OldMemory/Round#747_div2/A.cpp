#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
ll n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		ll temp=1;
		while(n%2==0)n/=2,temp*=2;
		ll l=n/2,r=n-l;
		l-=temp-1;
		r+=temp-1;
		printf("%lld %lld\n",l,r);
	}


	return 0;
}
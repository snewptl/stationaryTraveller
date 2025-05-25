#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
ll a,b,c;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("%lld %lld %lld\n",a+b*c,b,c);
		
	}


	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
ll x,y,n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		if(n%2!=0)puts("-1");
		else {
			n/=2;
			if(n==1)puts("-1");
			else {
				x=n/3;
				if(n%3!=0)x++;
				y=n/2;
				printf("%lld %lld\n",x,y);
			}

		}

	}


	return 0;
}
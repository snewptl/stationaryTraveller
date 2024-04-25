#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
ll a,b,to;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		ll x,y;
		scanf("%lld%lld%lld",&a,&b,&to);
		x=a,y=b;
		int flag=0;
		while(min(x,y)>0){
			if(x>y)swap(x,y);
			if(x==to||y==to)flag=1;
			if(y>=to&&(y-to)%x==0)flag=1;
			y%=x;
		}
		if(to==x||to==y)flag=1;
		if(flag)printf("YES\n");
		else printf("NO\n");
	}


	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
ll l,r;
ll solve(ll x){
    if(!x)return 0;
    ll y=(long long)sqrt(x+0.5);
    while((y)*(y)>x)y--;
    return y*3-(x<y*(y+1))-(x<y*(y+2));
}
int main(){
        // printf("%lld\n",(long long )sqrt(1000000000000000000));
        // printf("%lld\n",(long long )sqrt(999999999999999999));
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",solve(r)-solve(l-1));
        // printf("%lld\n",solve(r));
	}


	return 0;
}
/*
1
1000000000000000000 
1000000000000000000 
*/
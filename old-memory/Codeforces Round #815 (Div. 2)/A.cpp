#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
ll gcd(ll x, ll y){
    return y?gcd(y,x%y):x;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        ll a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(a==0&&c==0)puts("0");
        else if(a*c==0)puts("1");
        else {
            ll x=a*d,y=b*c;
            ll cd=gcd(x,y);
            x/=cd,y/=cd;
            if(x==1&&y==1)puts("0");
            else if(x!=1&&y!=1)puts("2");
            else puts("1");

        }
	}


	return 0;
}
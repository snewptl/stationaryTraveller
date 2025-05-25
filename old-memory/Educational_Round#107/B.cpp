#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll a,b,c;
ll x,y;
ll mi[50];
int main(){
    int T;scanf("%d",&T);
	mi[0]=1;
	for(int i=1;i<=9;i++)mi[i]=mi[i-1]*10;
    while(T--){
        scanf("%lld%lld%lld",&a,&b,&c);
		ll z=mi[c-1];
		y=mi[b-1];
		x=mi[a-1]+z;
		printf("%lld %lld\n",x,y);
    }


    return 0;
}
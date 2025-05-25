#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+10;
ll A,B,n;
ll a[maxn],b[maxn];
int main(){
    ll T;scanf("%lld",&T);
    while(T--){
		scanf("%lld%lld%lld",&A,&B,&n);
		ll mx=0;
		for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(ll i=1;i<=n;i++)scanf("%lld",&b[i]);
		for(ll i=1;i<=n;i++){
			if(mx<a[i])mx=a[i];
			B-=((b[i]-1)/A+1)*a[i];
		}
		if(B+mx<=0)printf("NO\n");
		else printf("YES\n");
    }


    return 0;
}
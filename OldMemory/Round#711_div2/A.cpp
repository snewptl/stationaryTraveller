#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll n;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
		for(ll i=n;;i++){
			ll x=i,sum=0;
			while(x){
				sum+=x%10;
				x/=10;
			}
			if(gcd(sum,i)!=1){
				printf("%lld\n",i);
				break;
			}
		}
    }


    return 0;
}
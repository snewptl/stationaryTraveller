#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll n,ans[maxn];
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main(){
    int T=1;
    while(T--){
		scanf("%lld",&n);
		ll cnt=0,sum=1;
		for(ll i=1;i<n;i++){
			if(gcd(i,n)==1){
				sum*=i,sum%=n;
				ans[++cnt]=i;
			}
		}
		if(sum!=1){
			printf("%lld\n",cnt-1);
			for(int i=1;i<=cnt;i++){
				if(ans[i]==sum)continue;
				printf("%lld ",ans[i]);
			}			
		}
		else {
			printf("%lld\n",cnt);
			for(int i=1;i<=cnt;i++){
				printf("%lld ",ans[i]);
			}
		}

    }


    return 0;
}
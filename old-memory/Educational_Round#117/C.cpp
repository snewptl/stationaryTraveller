#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
ll k,x;
ll ans;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&k,&x);
		x--;
		ll tot=(1+k)*k/2+k*(k-1)/2;
		ans=0;
		if(k==1){
			printf("1\n");
		}
		else if(x>=tot){
			printf("%lld\n",2*k-1);
		}
		else {
			ll pre=k*(k+1)/2;
			if(x>=pre){
				x-=pre;
				ll l=0,r=k-1;
				ll mx=0;
				while(l<=r){
					ll mid=l+r>>1;
					if((2*k-mid-1)*mid/2<=x)mx=max(mid,mx),l=mid+1;
					else r=mid-1;
				}
				mx++;
				printf("%lld\n",mx+k);
			}
			else {
				ll temp=sqrt(2*x);
				ll i;
				for(i=max(0ll,temp-5);i<=min(temp+5,k);i++){
					if(i*(i+1)/2>x)break;
				}
				printf("%lld\n",i);
			}

		}
	}	


	return 0;
}
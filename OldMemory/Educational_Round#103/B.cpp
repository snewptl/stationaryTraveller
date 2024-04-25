#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
ll k,a[105];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%lld",&n,&k);
		ll sum=0,ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		sum=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]*100>(sum+ans)*k){
				ans=(a[i]*100-1)/k+1-sum;
			}
			sum+=a[i];
		}
		printf("%lld\n",ans);
    }


    return 0;
}
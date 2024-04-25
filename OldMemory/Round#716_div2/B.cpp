#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll mod=1e9+7;
int n,k;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
		ll ans=1;
		for(int i=1;i<=k;i++){
			ans*=n;ans%=mod;
		}
		printf("%lld\n",ans);
    }


    return 0;
}
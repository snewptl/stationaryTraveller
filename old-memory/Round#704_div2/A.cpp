#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll p,a,b,c;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
		ll ans=1e18;
		ans=min((a-p%a)%a,(b-p%b)%b);
		ans=min(ans,(c-p%c)%c);
		printf("%lld\n",ans);
    }


    return 0;
}
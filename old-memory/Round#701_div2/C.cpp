#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int a,b,x,y;
ll ans;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&y,&x);
		ans=0;
		for(int i=1;i<=x;i++){
			int j=y/i,k=i;
			i=y/j;
			if(min(j,x+1)-i-1<=0)break;
			ans+=(i-k+1)*1LL*(min(j,x+1)-i-1);
		}
		printf("%lld\n",ans);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n;
ll a[maxn],b[maxn],c[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		ll ans=0,tmp=0,k=0;
		for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
		ll l=abs(a[2]-b[2])+2;
		ans=l+c[2]-1;
		for(int i=3;i<=n;i++){
			if(a[i]==b[i]){
				ans=max(ans,2+c[i]-1);
				l=2;
			}
			else if(a[i]<b[i]){
				l=max(b[i]-a[i],l+a[i]-1+c[i-1]-b[i])+2;
				ans=max(ans,l+c[i]-1);
			}
			else {
				l=max(a[i]-b[i],l+b[i]-1+c[i-1]-a[i])+2;
				ans=max(ans,l+c[i]-1);
			}
		}
		printf("%lld\n",ans);
    }


    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,q,k,l,r;
int a[maxn],dis[maxn],sum[maxn];
int main(){
    scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dis[i]=a[i]-a[i-1]-1;
		sum[i]=sum[i-1]+dis[i];
	}
	while(q--){
		scanf("%d%d",&l,&r);
		int ans=((sum[r]-sum[l])*2+k-a[r]+a[l]-1);
		printf("%d\n",ans);
	}
    return 0;
}
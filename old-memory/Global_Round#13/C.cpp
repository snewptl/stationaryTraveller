#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,a[maxn],b[maxn];
ll ans;
int main(){
    int T;scanf("%d",&T);
    while(T--){
		ans=0;
        scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(a[i]<=1)a[i]=1;
			if(b[i]>a[i]-1)
				b[i+1]+=b[i]-(a[i]-1);
			else ans+=a[i]-1-b[i];
			for(int j=2+i;j<=min(a[i]+i,n);j++){
				b[j]++;
			}
		}
		printf("%lld\n",ans);
    }


    return 0;
}
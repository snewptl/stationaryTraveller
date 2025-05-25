#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+10;
ll a[maxn],b[maxn];
int n;
ll sum,ans;
int main(){
    int T=1;
    while(T--){
        scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
		for(int i=1;i<=n;i++)sum+=a[i]*b[i];
		ans=sum;
		for(int i=1;i<=n;i++){
			ll temp=sum;
			int len=min(i-1,n-i);
			for(int j=1;j<=len;j++){
				temp+=a[i-j]*b[j+i]+a[i+j]*b[i-j]-a[i-j]*b[i-j]-a[i+j]*b[i+j];
				ans=max(temp,ans);
			}
		}
		for(int i=1;i<=n;i++){
			ll temp=sum;
			int len=min(i,n-i);
			for(int j=1;j<=len;j++){
				temp+=a[i-j+1]*b[j+i]+a[i+j]*b[i-j+1]-a[i-j+1]*b[i-j+1]-a[i+j]*b[i+j];
				ans=max(ans,temp);
			}
		}
		printf("%lld\n",ans);
    }



    return 0;
}
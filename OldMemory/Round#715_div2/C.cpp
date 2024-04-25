#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e3+10;
const ll MX=1e18;
int n;
int a[maxn];
ll dp[maxn][maxn];
int main(){
    int T=1;
    while(T--){
        scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++)dp[i][j]=MX;
		}
		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			dp[0][i]=dp[0][i-1]+a[n-i+1]-a[1];
			dp[i][0]=dp[i-1][0]+a[n]-a[i];
			
		}
		ll ans=min(dp[0][n],dp[n][0]);
		for(int i=1;i<=n;i++){
			for(int j=1;i+j<=n;j++){
				dp[i][j]=min(dp[i-1][j]+a[n-j]-a[i],dp[i][j-1]+a[n-j+1]-a[i+1]);
			}
			ans=min(ans,dp[i][n-i]);
		}
		printf("%lld\n",ans);
    }


    return 0;
}
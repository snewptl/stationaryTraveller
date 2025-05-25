#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn],b[maxn];
int dp[105][20005];
int sum;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		int sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
		for(int i=1;i<=n;i++)scanf("%d",&b[i]),sum+=b[i];
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=1e4;j++){
				if(dp[i-1][j])dp[i][j+a[i]]=1,dp[i][j+b[i]]=1;
			}
		}
		int ed=0;
		for(int j=0;j<=sum/2;j++){
			if(dp[n][j])ed=j;
		}
		// printf("^%d\n",ed);a
		for(int i=n;i>=1;i--){
			if(ed>=b[i]&&dp[i-1][ed-b[i]]){
				swap(a[i],b[i]);
			}
			ed-=a[i];
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans+=(a[i]+a[j])*(a[i]+a[j]);
				ans+=(b[i]+b[j])*(b[i]+b[j]);
			}
		}
		// for(int i=1;i<=n;i++)printf("%d\n",a[i]);
		printf("%lld\n",ans);
	}


	return 0;
}
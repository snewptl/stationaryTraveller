#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int ans[maxn],dp[2][maxn];
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=k;(i-k+1)*(i+k)/2<=n;i++){
		int st=(i-k+1)*(i+k)/2;
		for(int j=st;j<=n;j++){
			if(dp[0][j-i])dp[1][j]=dp[0][j-i];
			else if(i==k&&j==k){
				dp[1][j]=1;
			}
			dp[1][j]+=dp[1][j-i];
			if(dp[1][j]>=mod)dp[1][j]-=mod;
			ans[j]+=dp[1][j];
			if(ans[j]>=mod)ans[j]-=mod;
			// printf("##%d %d %lld\n",i,j,dp[1][j]);
		}
		for(int j=1;j<=n;j++){
			swap(dp[0][j],dp[1][j]);
			dp[1][j]=0;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);


	return 0;
}
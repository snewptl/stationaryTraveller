#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e2+10;
int n;
ll mod;
ll dp[maxn][maxn];
ll c[maxn][maxn];
ll mi[maxn];
void init(){
	mi[0]=1;
	for(int i=1;i<=n;i++)mi[i]=mi[i-1]*2,mi[i]%=mod;
	for(int i=0;i<=n;i++)c[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
}
int main(){
	scanf("%d%lld",&n,&mod);
	init();dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<=i-j-1;k++){
				dp[i][j+k]=(dp[i][j+k]+dp[i-j-1][k]*mi[j-1]%mod*c[j+k][k]%mod)%mod;
			}
			
		}
		dp[i][i]+=mi[i-1];

	}
	ll ans=0;
	for(int i=0;i<=n;i++){
		ans=(ans+dp[n][i])%mod;
	}
	printf("%lld\n",ans);
    return 0;
}
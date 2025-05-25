#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e3+10;
const ll mod=1e9+7;
ll dp[maxn][maxn][2];
char s[maxn];
char mp[maxn][maxn];
int n,m;
int r[maxn][maxn],c[maxn][maxn];
struct Tree{
	ll lazy,v;
}t[maxn*2][maxn*2];
void qu
int main(){
    scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		for(int j=1;j<=m;j++)
		mp[i][j]=s[j-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			r[i][j]=r[i][j+1];
			if(mp[i][j]=='R')r[i][j]++;
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=n;i>=1;i--){
			c[i][j]=c[i+1][j];
			if(mp[i][j]=='R')c[i][j]++;
		}
	}
	dp[1][0][1]=1;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			query(i,j-1);query(i-1,j);
			if(mp[i][j-1]!='R')dp[i][j][1]+=dp[i][j-1][0]+dp[i][j-1][1];
			if(mp[i-1][j]!='R')dp[i][j][0]+=dp[i-1][j][0]+dp[i-1][j][1];
			dp[i][j][1]%=mod,dp[i][j][0]%=mod;			
			if(mp[i][j]=='R'){
				updatec(i+1,n+1-c[i][j],j,dp[i][j][0]);
				// for(int k=1;k<=n-i+1-c[i][j];k++){
				// 	dp[i+k][j][0]+=dp[i][j][0];
				// }
				updater(i,j+1,m+1-r[i][j],dp[i][j][1])
				// for(int k=1;k<=m-j+1-r[i][j];k++){
				// 	dp[i][j+k][1]+=dp[i][j][1];
				// }
				dp[i][j][1]=dp[i][j][0]=0;
			}
		}
	}
	printf("%lld\n",(dp[n][m][0]+dp[n][m][1])%mod);

    return 0;
}
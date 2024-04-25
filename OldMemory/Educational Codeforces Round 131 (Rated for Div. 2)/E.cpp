#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=5e3+5;
const ll mod=998244353;
const double eps=1e-10;
int dp[2][maxn][maxn];
int vis[maxn],lst[maxn];
int n,m,ans;
char s[maxn],t[maxn];
void init(){
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=m+1;j++)dp[0][i][j]=dp[1][i][j]=0;
		vis[i]=0;
		lst[i]=m+1;
	}
	ans=1e9;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		scanf("%s%s",s+1,t+1);
		init();

		int pos=1;
		for(int i=1;i<=n;i++){
			vis[i]=vis[i-1];
			if(pos<=m){
				if(s[i]==t[pos])pos++,vis[i]++;
			}
		}
		dp[0][0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=vis[i];j++){
				if(s[i]!=t[j])dp[0][i][j]=0;
				else {
					dp[0][i][j]=dp[0][i-1][j-1]+1;
				}
			}
		}

		pos=m;
		for(int i=n;i>=1;i--){
			lst[i]=lst[i+1];
			if(pos>=1){
				if(s[i]==t[pos])pos--,lst[i]--;
			}
		}
		dp[1][n+1][m+1]=0;
		for(int i=n;i>=1;i--){
			for(int j=m;j>=lst[i];j--){
				if(s[i]!=t[j])dp[1][i][j]=0;
				else {
					dp[1][i][j]=dp[1][i+1][j+1]+1;
				}
			}
		}

		for(int i=1;i<=n;i++){
			if(dp[1][i][1]){
				ans=n;
				if(i==1)ans=min(ans,n-dp[1][1][1]);
			}
			
		}

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(dp[0][i][j]&&dp[1][i][j]){
					int idx=i-dp[0][i][j]+1;
					int idy=i+dp[1][i][j]-1;
					ans=min(ans,n-idy+1+idx-1+i-j);
				}
			}
		}

		if(ans==1e9)puts("-1");
		else printf("%d\n",ans);
	}


	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e3+5;
const ll mod=998244353;
const double eps=1e-10;
pii dp[maxn][maxn];
int n,m;
int a[maxn][maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
		}
		if((n+m)%2==0)puts("NO");
		else {
			if(a[1][1]==1)dp[1][1]={1,1};
			else dp[1][1]={0,0};
			for(int i=2;i<=n;i++)
				dp[i][1]={dp[i-1][1].first+(a[i][1]==1),dp[i-1][1].first+(a[i][1]==1)};
			for(int i=2;i<=m;i++)
				dp[1][i]={dp[1][i-1].first+(a[1][i]==1),dp[1][i-1].first+(a[1][i]==1)};
						
			for(int i=2;i<=n;i++){
				for(int j=2;j<=m;j++){
					int l=min(dp[i][j-1].first,dp[i-1][j].first);
					int r=max(dp[i][j-1].second,dp[i-1][j].second);
					dp[i][j]={l,r};
					if(a[i][j]==1)dp[i][j]={l+1,r+1};
				}
			}
			if(dp[n][m].first<=(n+m)/2&&dp[n][m].second>=(n+m)/2)puts("YES");
			else puts("NO");
		}


	}


	return 0;
}
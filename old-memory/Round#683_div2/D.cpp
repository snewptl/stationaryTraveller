#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+10;
int n,m;
char a[maxn],b[maxn];
int dp[maxn][maxn];
int ans=0;
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s%s",a+1,b+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
			dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
			if(a[i]==b[j])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
			ans=max(dp[i][j],ans);
		}
	}
	printf("%d\n",ans);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,dp[maxn][2],a[maxn],vis[maxn];
char s[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%s",&n,s);
        for(int i=1;i<=n;i++)vis[i]=s[i-1]-'0';
        for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(vis[i]){
                dp[i][1]=max(dp[i-1][1],dp[i-1][0])+a[i];
                dp[i][0]=dp[i-1][0]+a[i-1];
            }
            else {
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            }
        }
        printf("%d\n",max(dp[n][1],dp[n][0]));
	}


	return 0;
}
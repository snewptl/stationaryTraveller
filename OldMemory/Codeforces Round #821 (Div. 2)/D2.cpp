#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=5e3+5;
const ll mod=998244353;
const ll inf=1e18;
const double eps=1e-10;
int n,x,y,a[maxn],b[maxn],vis[maxn],pre[maxn];
char s[maxn],t[maxn];
int cnt;
ll ans;
ll dp[maxn][maxn][2];
void init(){
    ans=0;
    cnt=0;
    for(int i=1;i<=n;i++)vis[i]=0;
    for(int i=0;i<=n+2;i++){
        for(int j=0;j<=n+2;j++)dp[i][j][0]=dp[i][j][1]=inf;
    }
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d%d%s%s",&n,&x,&y,s,t);
        init();
        for(int i=1;i<=n;i++)a[i]=s[i-1]-'0';
        for(int i=1;i<=n;i++)b[i]=t[i-1]-'0';
        int lst=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=b[i]){
                cnt++;
                vis[i]=1;
                pre[i]=lst;
                lst=i;
            }
        }
        if(cnt%2)puts("-1");
        else {
            if(vis[1])dp[1][0][1]=0;
            else dp[1][0][0]=0;
            for(int i=2;i<=n;i++){
                for(int j=0;j<i;j++){
                    if(vis[i]){
                        // dp[i][j][0]=min(dp[i-1][j][1]+min(x,2*y),min(dp[i-1][j+1][0],dp[i-1][j][1])+y);
                        dp[i][j][0]=min(dp[i-1][j][1]+min(x,2*y),dp[i-1][j+1][0]+y);
                        if(j)
                            dp[i][j][0]=min(dp[i-1][j][1]+y,dp[i][j][0]);
                        if(j)
                            dp[i][j][1]=min(dp[i-1][j][0],dp[i-1][j-1][1]);
                        else 
                            dp[i][j][1]=dp[i-1][j][0];
                        if(pre[i])
                            dp[i][j][0]=min(dp[pre[i]][j][1]+1ll*(i-pre[i])*x,dp[i][j][0]);
                    }
                    else {
                        if(j)
                            dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j-1][1]);
                        else 
                            dp[i][j][0]=dp[i-1][j][0];
                    }
                }
            }
            printf("%lld\n",dp[n][0][0]);
        }
	}


	return 0;
}
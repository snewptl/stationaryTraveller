#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int dp[maxn][2],n;
char s[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%s",&n,s+1);
        dp[n+1][0]=dp[n+1][1]=0;
        for(int i=n;i>=1;i--){
            if(s[i]=='0'){
                dp[i][1]=dp[i+1][1];
                dp[i][0]=dp[i+1][1]+1;
            }
            else {
                dp[i][1]=dp[i+1][0]+1;
                dp[i][0]=dp[i+1][0];
            }
        }
        int ans=dp[1][0],cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]-'0'!=cnt%2){
                cnt++;
            }
            ans=min(dp[i+1][cnt%2]+cnt,ans);
        }
        printf("%d\n",ans);
	}


	return 0;
}
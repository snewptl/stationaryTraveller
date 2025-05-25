#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int dp[405][205],n,ans;
int a[205];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);ans=1e9+10;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=0;i<=400;i++)
            for(int j=1;j<=n;j++)
            dp[i][j]=1e9+10;
        for(int i=1;i<=400;i++){
            for(int k=1;k<=min(i,n);k++){
                dp[i][k]=min(dp[i][k],dp[i-1][k]);
                dp[i][k]=min(dp[i][k],dp[i-1][k-1]+abs(a[k]-i));
            }
        }
        for(int i=1;i<=400;i++){
            ans=min(dp[i][n],ans);
        }
        printf("%d\n",ans);
    }


    return 0;
}
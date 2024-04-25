#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;

typedef long long LL;

LL dp[2][4005][2],mem[2][2][4005],sum[2][2][4005];
LL cnt[4005][2];

int main (){

    int t,n;
    scanf("%d",&t);

    for(int kk=1;kk<=t;kk++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld%lld",&cnt[i][0],&cnt[i][1]);
        mem[0][0][0]=sum[0][0][0]=0;
        mem[1][0][n+1]=sum[1][0][n+1]=0;
        mem[0][1][0]=sum[0][1][0]=0;
        mem[1][1][n+1]=sum[1][1][n+1]=0;
        for(int i=1;i<=n;i++){
            sum[0][0][i]=sum[0][0][i-1]+cnt[i][0];
            sum[0][1][i]=sum[0][1][i-1]+cnt[i][1];
            mem[0][0][i]=mem[0][0][i-1]+sum[0][0][i-1];
            mem[0][1][i]=mem[0][1][i-1]+sum[0][1][i-1];
        }
        for(int i=n;i>=1;i--){
            sum[1][0][i]=sum[1][0][i+1]+cnt[i][0];
            sum[1][1][i]=sum[1][1][i+1]+cnt[i][1];
            mem[1][0][i]=mem[1][0][i+1]+sum[1][0][i+1];
            mem[1][1][i]=mem[1][1][i+1]+sum[1][1][i+1];
        }
        dp[0][1][0]=cnt[1][0]+cnt[2][1];
        dp[0][1][1]=cnt[2][0]+cnt[1][1];
        int cur=0,pre=1;
        for(int i=3;i<=n;i++){
            cur^=1;
            pre^=1;
            for(int j=1;j<i;j++){
                for(int k=0;k<=1;k++){
                    if(j!=i-1)
                        dp[cur][j][k]=dp[pre][j][k]+cnt[i][k^1]*(i-j);
                    if(j==i-1){
                        dp[cur][j][k]=mem[0][k][i-1]+sum[0][k][i-1]+cnt[i][k^1];
                        for(int p=1;p<j;p++){
                            LL tot=sum[1][k][(j+p+1)/2+1]-sum[1][k][j+1];
                            LL add=mem[0][k][j+1]-mem[0][k][(j+p+1)/2]
                                    -sum[0][k][(j+p+1)/2]*abs(j+1-(j+p+1)/2);
                            LL subt=mem[1][k][(j+p+1)/2+1]-mem[1][k][j+1]
                                    -sum[1][k][j+1]*abs(j-(j+p+1)/2)+((j+p+1)/2+1-p)*tot;
                            dp[cur][j][k]=min(dp[cur][j][k],dp[pre][p][k^1]+add-subt+cnt[i][k^1]);
                        }

                    }
                }
            }
        }
        LL ans=min(dp[cur][1][0],dp[cur][1][1]);
        for(int i=2;i<n;i++)
            ans=min(min(dp[cur][i][0],dp[cur][i][1]),ans);

        printf("Case #%d: %lld\n",kk,ans);
    }
    return 0;
}
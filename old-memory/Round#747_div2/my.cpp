#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=4e3+5;
const ll inf=1e18;
int n;
ll dp[2][maxn],pre[2][maxn],a[2][maxn],val[2][maxn][maxn];
int main(){
    
    // freopen("gen.in","r",stdin);
    // freopen("my.out","w",stdout);
    int T;scanf("%d",&T);
    for(int cs=1;cs<=T;cs++){
        scanf("%d",&n);
        for(int sgn=0;sgn<2;sgn++){
            for(int i=0;i<=n;i++){
                dp[sgn][i]=inf;
            }   
        }
        for(int i=1;i<=n;i++){
            scanf("%lld%lld",&a[0][i],&a[1][i]);
            pre[0][i]=pre[0][i-1]+a[0][i];
            pre[1][i]=pre[1][i-1]+a[1][i];
        }
        for(int sgn=0;sgn<2;sgn++){
            for(int len=1;len<=n;++len)
                for(int i=1;i+len-1<=n;++i)
                    if(len<=2)val[sgn][i][i+len-1]=0;
                    else val[sgn][i][i+len-1]=val[sgn][i+1][i+len-2]+pre[sgn][i+len-2]-pre[sgn][i];
            for(int i=2;i<=n;i++)
                val[sgn][0][i]=val[sgn][0][i-1]+pre[sgn][i-1];
        }
        dp[0][0]=dp[1][0]=0;
        for(int i=2;i<=n;i++){
            for(int sgn=0;sgn<2;sgn++){
                for(int j=i-2;j>=0;j--){
                    dp[sgn][i-1]=min(dp[sgn^1][j]+val[sgn][j][i],
                        dp[sgn][i-1]);
                }
            }
        }

        for(int sgn=0;sgn<2;sgn++){
            val[sgn][n][n]=0;
            for(int i=n-1;i>=0;i--){
                val[sgn][i][n]=val[sgn][i+1][n]+pre[sgn][n]-pre[sgn][i];
            }
        }
        ll ans=inf;
        for(int i=1;i<n;i++)
            for(int sgn=0;sgn<2;sgn++)
                ans=min(ans,dp[sgn][i]+val[sgn^1][i][n]);
        printf("Case #%d: %lld\n",cs,ans);

    }
    return 0;
}
/*
3
5
10 1
4 1
7 1
6 1
3 1
15
1000000 1
100000 1
10000 1
1000 1
100 1
1000000 1
100000 1
10000 1
1000 1
100 1
1000000 1
100000 1
10000 1
1000 1
100 1
2
10 5
4 3

*/
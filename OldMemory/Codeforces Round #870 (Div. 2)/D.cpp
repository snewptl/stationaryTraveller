#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxn=4e5+5;
const double eps=1e-10;
const int inf=1e9;
int ans;
int n,a[maxn];
int dp[21][maxn][2][3];
int mx[21][maxn];
void query(int l){

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=0;(1<<i)<2*n;i++){
            for(int j=1;j<=n*2;j++){
                mx[i][j]=0;
                for(int k=0;k<2;k++){
                    for(int t=1;t<=2;t++)
                    dp[i][j][k][t]=0;
                }
            }
        }
        for(int j=1;j<=n;j++)
            dp[0][j][0][1]=dp[0][j][1][1]=a[j];
        for(int j=1;j<=n;j++)
            mx[0][j]=a[j];
        for(int i=1;(1<<i)<2*n;i++){
            int len=(1<<(i-1));
            for(int j=1;j<=n;j++){
                mx[i][j]=max(mx[i-1][j],mx[i-1][j+len]);
            }
        }
        for(int i=1;(1<<i)<2*n;i++){
            int len=(1<<(i-1));
            for(int j=1;j<=n;j++){
                dp[i][j][0][1]=max(dp[i-1][j][0][1],dp[i-1][j+len][0][1]-len);
                dp[i][j][0][2]=max(dp[i-1][j][0][2],max(dp[i-1][j+len][0][2]-len,mx[i-1][j]+dp[i-1][j+len][0][1]-len));
                
                dp[i][j][1][1]=max(dp[i-1][j+len][1][1],dp[i-1][j][1][1]-len);
                dp[i][j][1][2]=max(dp[i-1][j+len][1][2],max(dp[i-1][j][1][2]-len,mx[i-1][j+len]+dp[i-1][j][1][1]-len));

                ans=max(ans,max(dp[i-1][j][1][1]+dp[i-1][j+len][0][2]-1,dp[i-1][j][1][2]+dp[i-1][j+len][0][1]-1));
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
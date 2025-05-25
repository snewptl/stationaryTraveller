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
const int maxn=3e5+5;
const double eps=1e-10;
int n,a[maxn];
int dp[maxn][2];
void solve(){
    for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=-1;
    int mx=0;
    for(int i=n;i>=1;i--){
        if(i+a[i]==n)dp[i][0]=dp[i][1]=1;
        else if(i+a[i]<n){
            if(dp[i+a[i]+1][0]!=-1)dp[i][0]=dp[i+a[i]+1][0]+1;
            dp[i][1]=dp[i+a[i]+1][1]+1;
        }
        mx=max(dp[i][0],mx);
        dp[i][1]=max(dp[i][1],mx+1);
    }
    for(int i=1;i<n;i++){
        if(dp[i+1][0]==a[i])cout<<"0 ";
        else if(dp[i+1][1]>=a[i])cout<<"1 ";
        else if(dp[i+1][0]!=-1)cout<<"1 ";
        else cout<<"2 ";
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        solve();
    }

    return 0;
}
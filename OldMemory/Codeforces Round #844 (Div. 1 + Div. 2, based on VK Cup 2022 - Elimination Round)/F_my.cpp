#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const int maxn=1000;
const double eps=1e-10;
int n,tot,x,y;
int ans,mod;
int dp[5][1005][1005];
void init(){
    int cur=sqrt(n+0.5);
    if(cur*cur==n)tot=cur*2;
    else if(cur*(cur+1)>=n)tot=cur*2+1;
    else tot=cur*2+2;
    x=tot/2;
    y=tot-x;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T,opt;cin>>T>>opt;
    if(opt==2){
        cin>>mod;
        dp[0][0][maxn]=1;
        for(int i=0;i<4;i++){
            for(int j=0;j<=maxn;j++){
                for(int k=maxn;k>=1;k--){
                    if(j+k<=maxn)
                        (dp[i][j+k][k]+=dp[i][j][k])%=mod;
                    (dp[i][j][k-1]+=dp[i][j][k])%=mod;
                    
                    // if(dp[i][j][k])cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<'\n';
                }
                (dp[i+1][j][maxn]+=dp[i][j][0])%=mod;
            }
        }        
    }
    while(T--){ 
        cin>>n;
        init();
        if(opt==1){
            vector<vector<char>>mp(x,vector<char>(y,'#'));
            cout<<x<<" "<<y<<'\n';
            for(int i=0;i<x*y-n;i++)mp[0][i]='.';
            for(int i=0;i<x;i++){
                for(int j=0;j<y;j++)cout<<mp[i][j];
                cout<<'\n';
            }
        }   
        else {
            ans=0;
            for(int i=1;i<=tot;i++){
                int j=tot-i;
                int rem=i*j-n;
                if(rem<0)continue;
                (ans+=dp[4][rem][maxn])%=mod;
            }
            cout<<tot*2<<" "<<ans<<'\n';
        } 
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxn=2e3+5;
const double eps=1e-10;
int dp[maxn][maxn];
char s[maxn];
int n;
int solve(int l,int r){
    if(dp[l][r])return dp[l][r];
    if(l==r-1){
        if(s[l]==s[r])return dp[l][r]=3;
        else return dp[l][r]=1;
    }

    int res1,res2;

    res1=solve(l+1,r-1);
    if(res1==3){
        if(s[l]>s[r])res1=2;
        else if(s[l]<s[r])res1=1;
    }
    if(solve(l+2,r)==3){
        if(s[l]>s[l+1])res1=2;
        else if(s[l]==s[l+1]&&res1==1)res1=3;
    }
    if(solve(l+2,r)==2){
        res1=2;
    }
    
    res2=solve(l+1,r-1);
    if(res2==3){
        if(s[r]>s[l])res2=2;
        else if(s[r]<s[l])res2=1;
    }
    if(solve(l,r-2)==3){
        if(s[r]>s[r-1])res2=2;
        else if(s[r]==s[r-1]&&res2==1)res2=3;
    }
    if(solve(l,r-2)==2){
        res2==2;
    }

    if(res1==1||res2==1)return dp[l][r]=1;
    else if(res1==3||res2==3)return dp[l][r]=3;
    else return dp[l][r]=2;
}
int main(){
    int T=1;scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=n;j++)dp[i][j]=0;
        int res=solve(1,n);
        if(res==1)puts("Alice");
        else if(res==2)puts("Bob");
        else puts("Draw");
    }

    return 0;
}
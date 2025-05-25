/*
dp[i][j][0/1] pre i seg; have j pair; isHaveHalfSeg
init: all element <- inf
for i  in 1,n
    for  j in 0,n/2
        if seg[j].l > dp[i-1][j][0]
            dp[i][j][1] <- min{seg[j].r}
        if seg[j].l <= dp[i-1][j][1]
            dp[i][j][0] <- min{max(seg[j].r, dp[i-1][j-1][1])}
ans <- j, where dp[n][j][0] != inf
*/
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
const int maxn=2e5+5;
const double eps=1e-10;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){

    }

    return 0;
}
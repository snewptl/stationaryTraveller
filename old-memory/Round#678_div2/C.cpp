#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll maxn=1e3;
int n,x,pos,l,r,bi,sm;
ll ans;
ll dp[maxn+10][maxn+10],mi[maxn+10];
void init(){
    for(int i=0;i<=maxn;i++)dp[0][i]=1;
    for(int i=1;i<=maxn;i++){
        dp[i][i]=1;
        for(int j=i+1;j<=maxn;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
            dp[i][j]%=mod;
        }
    }
    mi[0]=1;
    for(ll i=1;i<=maxn;i++)mi[i]=mi[i-1]*i,mi[i]%=mod;
}
void find(){
    int le=0,ri=n,mid;
    while(le<ri){
        mid=le+ri>>1;
        if(pos<mid){
            l++,ri=mid;
        }
        else {
            r++,le=mid+1;   
            if(pos==mid)r--;
        }
    }
}
void get_ans(){
    ans=0;
    bi=n-x,sm=x-1;
    if(bi<l)return;
    if(sm<r)return;
    ans=dp[r][sm]*mi[r]%mod*dp[l][bi]%mod*mi[l]%mod*mi[n-l-r-1]%mod;
    // ans=dp[pos]+dp[n-1-pos];
}
int main(){
    init();
    scanf("%d%d%d",&n,&x,&pos);
    l=r=0;find();
    get_ans();
    printf("%lld\n",ans);
    return 0;
}
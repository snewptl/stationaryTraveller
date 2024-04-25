#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef double db;
const int maxn=2e5+5;
const ll inf=1e18;
const ll mod=998244353;
const double eps=1e-10;
pll lsr[3];
int h,s;
ll dp[5005];
int main(){
    for(int i=1;i<=2;i++){
        scanf("%lld%lld",&lsr[i].first,&lsr[i].second);
    }
    if(lsr[1].second>lsr[2].second)swap(lsr[1],lsr[2]);
    scanf("%d%d",&h,&s);
    for(int i=0;i<=h;i++)dp[i]=inf;
    dp[h]=0;
    for(int i=h;i>=1;i--){
        if(dp[i]==inf)continue;
        for(int j=1;j<=h;j++){
            ll t1=lsr[1].second*j;
            int k=t1/lsr[2].second;
            ll t2=(k+1)*lsr[2].second;

            int dam,to;

            dam=j*(lsr[1].first-s)+k*(lsr[2].first-s);
            if(k)dam+=s;
            to=max(i-dam,0);
            dp[to]=min(dp[i]+t1,dp[to]);

            dam=j*(lsr[1].first-s)+(k+1)*(lsr[2].first-s);
            dam+=s;
            to=max(i-dam,0);
            dp[to]=min(dp[to],dp[i]+t2);
        }
    }
    printf("%lld\n",dp[0]);


	return 0;
}
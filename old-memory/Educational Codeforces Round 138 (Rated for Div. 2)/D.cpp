#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=3e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
ll m,dp[maxn],ans,tot,pre[maxn];
int pri[maxn],vis[maxn],cnt;
void get_pri(){
    for(int i=2;i<=n;i++){
        if(!vis[i])pri[cnt++]=i;
        for(int j=0;j<cnt;j++){
            if(1ll*i*pri[j]>n)break;
            vis[i*pri[j]]=pri[j];
            if(i%pri[j]==0)break;
        }
    }
}
int main(){
    scanf("%d%lld",&n,&m);
    get_pri();
    ll tot=0;
    for(int i=0;i<cnt;i++){
        dp[pri[i]]=m/pri[i];
        for(int j=0;j<i;j++){
            dp[pri[i]]-=dp[pri[j]]/pri[i];
        }
        printf("%d %d\n",pri[i],dp[pri[i]]);
        tot+=dp[pri[i]];
    }
    // printf("%lld\n",tot);
    for(int i=n;i>=1;i--){
        ans+=1;
        ans*=(m-tot),ans%=mod;
        tot-=dp[i];
    }
    ll res=0;
    for(int i=n;i>=1;i--)res+=1,res*=m,res%=mod;
    printf("%lld %lld\n",res,(res-ans+mod)%mod);

	return 0;
}
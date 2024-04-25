#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=1e9+7;
const int maxn=2e5+5;
const double eps=1e-10;
vector<int>e[maxn];
int n,k;
ll sum[maxn],sz[maxn];
ll fac[maxn];
ll num=0;
ll ans;
ll qpow(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1)res*=x,res%=mod;
        x*=x,x%=mod;
        y/=2;
    }
    return res;
}
void dfs(int u,int p){
    sz[u]=1;
    for(auto v:e[u]){
        if(v==p)continue;
        dfs(v,u);
        ans+=(sum[u]+1)*sz[v]+(sum[v]+1)*sz[u];
        ans%=mod;
        sz[u]+=sz[v];
        sum[u]+=sz[v]+sum[v]+1;
        sum[u]%=mod;
    }
}
ll inv(ll x){
    return qpow(x,mod-2);
}
ll cal(ll x,ll y){
    return fac[x]*inv(fac[y])%mod*inv(fac[x-y])%mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    ans=(ans*inv(cal(n,k))%mod);
    if(k==1||k==3)ans=1;
    cout<<ans<<'\n';

    return 0;
}
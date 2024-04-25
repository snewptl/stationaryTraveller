#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k;
int a[maxn];
vector<int>e[maxn];
ll cnt[maxn],sz[maxn];
ll ans;
ll qpow(ll x, ll y){
    ll res=1;
    while(y){
        if(y&1)res*=x,res%=mod;
        x*=x,x%=mod;
        y/=2;
    }
    return res;
}
void dfs(int u,int p){
    sz[u]=cnt[u];
    for(auto v:e[u]){
        if(v==p)continue;
        dfs(v,u);
        sz[u]+=sz[v],sz[u]%=mod;
    }
    if(u!=1){

        ans+=sz[u]*(k-sz[u]+mod)%mod,ans%=mod;
    }
}
int main(){
    scanf("%d%d",&n,&k);
    ll st=qpow(2,n-1),inv2=qpow(2,mod-2);
    for(int i=1;i<=k;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]=1;
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
        ll ad=(cnt[u]+cnt[v])%mod,mul=cnt[u]*cnt[v]%mod;
        ll temp=inv2*ad%mod;
        ans-=temp*temp%mod,ans=(ans+mod)%mod;
        ans+=mul%mod,ans%=mod;
        // ans-=mod;
        cnt[u]=cnt[v]=temp;
        // printf("%lld %lld %lld\n",ad*16%mod,temp*temp*16%mod,ans*16%mod);
    }
    // printf("%lld\n",(ans-mod)*16%mod);
    dfs(1,0);
    ans*=qpow(1ll*k*(k-1)/2%mod,mod-2),ans%=mod;
    printf("%lld\n",ans*16%mod);
	return 0;
}
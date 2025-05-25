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
ll tot,ans;
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
        ans+=sz[u]*(tot-sz[u]+mod)%mod,ans%=mod;
    }
}
int main(){
    scanf("%d%d",&n,&k);
    ll st=qpow(2,n-1),inv2=qpow(2,mod-2);
    tot=st*k%mod;
    for(int i=1;i<=k;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]=1;
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
        // ll cu=cnt[u],cv=cnt[v];
        // cnt[u]*=inv2,cnt[u]%=mod,cnt[u]+=cv*inv2%mod,cnt[u]%=mod;
        // cnt[v]*=inv2,cnt[v]%=mod,cnt[v]+=cu*inv2%mod,cnt[v]%=mod;
        // ans-=cnt[u]*cnt[u]%mod*inv2%mod*inv2%mod;
        // ans-=cnt[v]*cnt[v]%mod*inv2%mod*inv2%mod;
        ll temp=(cnt[u]+cnt[v])*inv2%mod;
        ll ad=cnt[u]
        ans-=temp*temp%mod,ans%=mod;
        ans+=cnt[u]*cnt[v]%mod,ans%=mod;
        printf("^^%lld\n",ans);
        cnt[u]=cnt[v]=temp;
    }
    dfs(1,0);
    // for(int i=1;i<=n;i++)printf("%lld\n",cnt[i]);
    // ans*=qpow(2,2*(n-1)*(mod-2)),ans%=mod;
    ans*=qpow(k*(k-1)/2%mod,mod-2),ans%=mod;
    printf("%lld\n",ans);
	return 0;
}
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
vector<int>e[maxn];
int a[maxn],sz[maxn],fa[maxn];
ll sum[maxn];
set<pii>s[maxn];
int n,m;
void update(int u){
    if(s[u].empty())return;
    int p=fa[u];
    auto it=*s[u].begin();
    s[u].erase(it);
    s[p].erase({-sz[u],u});
    sum[u]-=sum[it.second];
    sz[u]-=sz[it.second];
    fa[u]=it.second;
    s[it.second].insert({-sz[u],u});
    sum[it.second]+=sum[u];
    fa[it.second]=p;
    sz[it.second]+=sz[u];
    s[p].insert({-sz[it.second],it.second});
}
void dfs(int u,int p){
    sum[u]=a[u];
    sz[u]=1;
    for(auto v:e[u]){
        if(v==p)continue;
        fa[v]=u;
        dfs(v,u);
        sum[u]+=sum[v];
        sz[u]+=sz[v];
        s[u].insert({-sz[v],v});
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    while(m--){
        int opt,x;
        cin>>opt>>x;
        if(opt==1){
            cout<<sum[x]<<'\n';
        }
        else {
            update(x);
        }
    }
    return 0;
}
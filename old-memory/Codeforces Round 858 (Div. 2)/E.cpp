#include<bits/stdc++.h>
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
int n,q,a[maxn],fa[maxn],dep[maxn];
ll dp[10000005];
int tot;
unordered_map<ll,int>mp[maxn];
int hsh(int x,int y){
    if(x>y)swap(x,y);
    ll temp=1ll*x*(n+1)+y;
    if(!mp[dep[x]].count(temp))mp[dep[x]][temp]=++tot;
    return mp[dep[x]][temp];
}
struct Que{
    int dep,idx,x,y;
    bool operator <(const Que &t) const {
        return dep>t.dep;
    }
}que[maxn];
void dfs(int u,int p){
    for(auto v:e[u]){
        if(v==p)continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
void init(){
    dfs(1,0);
}
ll get_ans(int x,int y){
    if(!x)return 0;
    if(dp[hsh(x,y)])return dp[hsh(x,y)];
    else {
        return dp[hsh(x,y)]=get_ans(fa[x],fa[y])+1ll*a[x]*a[y];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2;i<=n;i++){
        int p;cin>>p;
        fa[i]=p;
        e[p].push_back(i);
        e[i].push_back(p);
    }
    init();
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        // cin>>que[i].x>>que[i].y;
        // que[i].dep=dep[que[i].x];
        // que[i].idx=i;
        cout<<get_ans(x,y)<<'\n';
    }
    // sort(que+1,que+q+1);
    // for(int i=1;i<=q;i++){
    // }
    return 0;
}
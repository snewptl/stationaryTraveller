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
int n,m;
int a[maxn];
int fa[maxn],cnt[maxn];
vector<int>e[maxn];
set<pii>s[maxn];
bool check(){
    for(int i=1;i<=n;i++)if(cnt[i]==n&&!a[i])return true;
    return false;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void bfs(int u){
    cnt[u]=1;
    for(auto it:e[u])s[u].insert({a[it],it});
    while(!s[u].empty()&&
      s[u].begin()->first<=cnt[u]){ 

        auto it=*s[u].begin();
        int v=find(it.second);
        s[u].erase(it);
        if(v==u)continue;
        if(!s[v].size()){
            cnt[u]++;
            for(auto w:e[v]){
                s[u].insert({a[w],w});
            }
        }
        else {
            if(s[u].size()<s[v].size())swap(u,v);
            cnt[u]+=cnt[v];
            for(auto it:s[v])s[u].insert(it);            
        }
        fa[v]=u;
    }
}
void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
        cnt[i]=0;
        e[i].clear();
        s[i].clear();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>m;
        init();
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
            if(!a[i]&&i==find(i))bfs(i);        
        if(check())cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
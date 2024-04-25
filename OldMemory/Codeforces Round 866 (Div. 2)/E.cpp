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
int n;
pii rt;
int dep[maxn],fa[maxn];
vector<int>e[maxn];
void dfs(int u,int p){
    fa[u]=p;
    for(auto v:e[u]){
        if(v==p)continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
vector<int>path,ans;
int vis[maxn];
void init(){
    for(int i=rt.second;i;i=fa[i])path.push_back(i);
    reverse(all(path));
    for(auto it:path)vis[it]=1;
}
void solve(){
    for(int i=0;i<path.size();i+=2){
        ans.push_back(path[i]);
        if(i+1<path.size()){
            for(auto it:e[path[i+1]]){
                if(vis[it])continue;
                ans.push_back(it);
            }
        }
    }
    for(int i=(path.size()-1);i>0;i-=2){
        if(i%2==0)i--;
        ans.push_back(path[i]);
        if(i-1>=0){
            for(auto it:e[path[i-1]]){
                if(vis[it])continue;
                ans.push_back(it);
            }
        }
    }
    if(ans.size()==n){
        cout<<"YES\n";
        for(auto it:ans)cout<<it<<" ";
        cout<<'\n';
    }
    else {
        cout<<"NO\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    while(T--){
        cin>>n;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dep[1]=0; 
        dfs(1,0);
        for(int i=1;i<=n;i++)if(dep[i]>=dep[rt.first])rt.first=i;
        dep[rt.first]=0;
        dfs(rt.first,0);
        for(int i=1;i<=n;i++)if(dep[i]>=dep[rt.second])rt.second=i;
        init();
        solve();
    }

    return 0;
}
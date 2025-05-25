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
set<int,greater<int>>*pt_s[maxn];
map<int,int>*pt_mp[maxn];
int n;
vector<int>e[maxn];
int a[maxn];
int dp[2][maxn],son[maxn];
map<pii,int>idx;
void dfs_pos(int u,int p){
    size_t sz=0;
    for(auto v:e[u]){
        if(v==p)continue;
        dfs_pos(v,u);
        if(sz<pt_mp[v]->size())son[u]=v;
        sz=max(sz,pt_mp[v]->size());
    }
    if(!sz){
        pt_mp[u]=new map<int,int>;
        pt_s[u]=new set<int,greater<int>>;
        (*pt_mp[u])[a[u]]=1;
    }
    else pt_mp[u]=pt_mp[son[u]],pt_s[u]=pt_s[son[u]];
    for(auto v:e[u]){
        if(v==son[u]||v==p)continue;
        for(auto it:*(pt_mp[v])){
            (*pt_mp[u])[it.first]+=it.second;
            if((*pt_mp[u])[it.first]>=2)
                pt_s[u]->insert(it.first);
        }
    }
    if(!pt_s[u]->empty())
        dp[0][idx[{u,p}]]=*pt_s[u]->begin();
}
map<int,int>mp;
set<int,greater<int>>s;
set<int,greater<int>>*pre_s[maxn];
map<int,int>*pre_mp[maxn];
void dfs_neg(int u,int p){
    if(u==1){
        pre_mp[u]=new map<int,int>;
        pre_s[u]=new set<int,greater<int>>;
        (*pre_mp[u])[a[u]]=1;
    }
    else {
        pre_mp[u]=pre_mp[p];
        pre_s[u]=pre_s[p];
        (*pre_mp[u])[a[u]]++;
        if((*pre_mp[u])[a[u]]>=2)pre_s[u]->insert(a[u]);
    }
    for(auto v:e[u]){
        if(v==p||v==son[u])continue;
        for(auto it:*pt_mp[v]){
            (*pre_mp[u])[it.first]+=it.second;
            if((*pre_mp[u])[it.first]>=2)
                pre_s[u]->insert(it.first);               
        }
    }
    if(son[u]){
        if(!pre_s[u]->empty())
            dp[1][idx[{u,son[u]}]]=*pre_s[u]->begin();        
        dfs_neg(son[u],u);
    }

    for(auto v:e[u]){
        if(v==p||v==son[u])continue;
        for(auto it:*pt_mp[v]){
            pre_s[u]->erase(it.first);
            (*pre_mp[u])[it.first]-=it.second;
            if((*pre_mp[u])[it.first]>=2)
                pre_s[u]->insert(it.first);
        }
        dfs_neg(v,u);    
        if(!pre_s[u]->empty())
            dp[1][idx[{u,v}]]=*pre_s[u]->begin();
        for(auto it:*pt_mp[v]){
            (*pre_mp[u])[it.first]+=it.second;
            if((*pre_mp[u])[it.first]>=2)
                pre_s[u]->insert(it.first);
        }
    }
    if(!son[u])return;
    for(auto v:e[u]){
        if(v==son[u]||v==p)continue;
        for(auto it:*pt_mp[v]){
            mp[it.second]+=it.second;
            if(mp[it.second]>=2)s.insert(it.first);
        }
    }
    
}
void dp_rt(){
    dfs_pos(1,0);
    dfs_neg(1,0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        if(u>v)swap(u,v);
        e[u].push_back(v);
        e[v].push_back(u);
        idx[{u,v}]=idx[{v,u}]=i;
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    dp_rt();
    for(int i=1;i<n;i++)cout<<dp[0][i]+dp[1][i]<<"\n";
    return 0;
}
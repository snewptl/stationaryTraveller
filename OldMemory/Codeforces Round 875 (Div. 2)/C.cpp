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
int n,vis[maxn];
map<pii,int>rk;
set<pii>s;

void clear(){
    for(int i=1;i<=n;i++){
        e[i].clear();
        vis[i]=0;
    }
    s.clear();
    rk.clear();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
            rk[{u,v}]=rk[{v,u}]=i;
        }
        s.insert({0,1});
        vis[1]=1;
        int ans=0,pre=n+1;
        while(!s.empty()){
            auto it=s.lower_bound({pre,0});
            if(it==s.end())ans++,it=s.begin();
            pre=it->first;
            for(auto v:e[it->second]){
                if(!vis[v]){
                    s.insert({rk[{v,it->second}],v});
                    vis[v]=1;
                }
            }
            s.erase(it);
        }
        cout<<ans<<'\n';
    }

    return 0;
}
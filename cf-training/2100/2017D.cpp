#include<bits/stdc++.h>
#ifdef DEBUG_LOCAL
#include <mydebug/debug.h>
#endif
using ll = long long;
const int N = 5e5+5;
using namespace std;
using pi = pair<int,int>;
using ti = tuple<int,int,int,int>;
int T,n,u,v,del[N],fa[N],ct;  vector<int> g[N]; set<pi> t[N];
void dfs(int u,int f){
    t[u].emplace(0,u),fa[u] = f;
    for(int v : g[u]) if(v != f){
        dfs(v,u); auto [x,y] = *--t[v].end();
        t[u].emplace(x+1,y);
    }
}ti gt(int u){
    assert(t[u].size() >= 1);
    if(t[u].size() == 1) return {0,u,u,u};
    auto [x,y] = *--t[u].end();
    auto [p,q] = *--(--t[u].end());
    return {x + p,max(y,q),min(y,q),u};
}void los(){
    cin >> n;
    for(int i = 1;i <= n;i ++) g[i].clear(),del[i] = 0,t[i].clear();
    for(int i = 1;i < n;i ++) cin >> u >> v,g[u].push_back(v),g[v].push_back(u);
    ct = 0,dfs(1,0); priority_queue<ti> q;
    for(int i = 1;i <= n;i ++) q.emplace(gt(i));
    while(q.size()){
        auto [di,u,v,d] = q.top(); q.pop();
        if(del[d] || ti{di,u,v,d} != gt(d)) continue;
        cout << di + 1 << " " << u << " " << v << " ";
        while(u != d) del[u] = 1,u = fa[u];
        while(v != d) del[v] = 1,v = fa[v];
        del[d] = 1; 
        auto [x,y] = *--t[d].end();
        while(fa[d] && !del[fa[d]]){
            d = fa[d];
            if(t[d].count({++x,y})) t[d].erase({x,y});
            q.emplace(gt(d));
            if(fa[d]){
                auto [a,b] = *--t[d].end();
                t[fa[d]].emplace(a+1,b);
            }
        }
    }cout << "\n";
}int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    for(cin >> T;T --;) los();
}
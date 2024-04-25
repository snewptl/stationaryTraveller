#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<ll,pii> Edge;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const ll inf=1e18;
const double eps=1e-10;
ll dp[505][505],link[505][505];
int n,m;
priority_queue<pair<pll,pii>,vector<pair<pll,pii>>,greater<pair<pll,pii>>>q;
void solve(){
    while(!q.empty()){
        auto it=q.top();q.pop();
        int u=it.second.first,v=it.second.second;
        ll val=it.first.first,w=it.first.second;
        // printf("%lld %d %d\n",val,u,v);
        int vis[505];
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)if(dp[i][u]!=inf)vis[i]=1;
        for(int i=1;i<=n;i++){
            if(vis[i]){
                if(dp[i][v]>w+val+link[i][u]){
                    dp[i][v]=dp[v][i]=w+val+link[i][u];
                    link[i][v]=link[v][i]=min(link[v][i],dp[i][v]-w);
                    q.push({{dp[i][v],w},{i,v}});
                    q.push({{dp[i][v],w},{v,i}});
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     if(dp[i][v]!=inf){
        //         if(dp[i][u]>w+val){
        //             dp[i][u]=dp[u][i]=min(dp[i][u],w+val);
        //             q.push({{dp[i][u],w},{i,u}});
        //         }
        //     }
        // }        
    }
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)dp[i][j]=link[i][j]=inf;
        }
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            dp[u][v]=dp[v][u]=w;
            link[u][v]=link[v][u]=0;
            q.push({{w,w},{u,v}});
             q.push({{w,w},{v,u}});
        }
        solve();
        printf("%lld\n",dp[1][n]);
	}


	return 0;
}
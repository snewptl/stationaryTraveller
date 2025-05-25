#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
vector<int>e[maxn];
int n,a[maxn],b[maxn];
int len,cntedge,cntnode;
ll ans;
int dep[maxn];
void dfs(int u,int p){
    cntedge+=e[u].size();
    cntnode++;
    for(auto v:e[u]){
        if(!dep[v]){
            dep[v]=dep[u]+1;
            dfs(v,u);
        }
        if(v==u)len=1;  
    }
}
void solve(){
    ans=1;
    for(int i=1;i<=n;i++){
        if(a[i]==b[i])ans*=n,ans%=mod;
    }
    for(int i=1;i<=n;i++)dep[i]=0;
    for(int i=1;i<=n;i++){
        if(!dep[i]){
            cntedge=0;
            cntnode=0;
            len=0;
            dep[i]=1;
            dfs(i,0);
            
            if(!len)len=2;
            ans*=len,ans%=mod;
            
            cntedge/=2;
            if(cntedge==cntnode-1)ans=0;
        }
    }
    printf("%lld\n",ans);
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)e[i].clear();
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        for(int i=1;i<=n;i++){
            e[a[i]].push_back(b[i]);
            e[b[i]].push_back(a[i]);
        }
        solve();
	}


	return 0;
}
/*
1
5
1 2 4 4 4
2 3 5 5 5
4
1 2 3 4
2 1 4 3
*/
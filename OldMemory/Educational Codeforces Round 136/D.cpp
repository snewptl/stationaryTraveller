#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k;
vector<int>e[maxn];
int dep[maxn],ans,cur;
void clear(){
    ans=1e9;
    for(int i=1;i<=n;i++)e[i].clear();
}
void dfs(int u,int mxdep){
    dep[u]=0;
    int res=0;
    for(auto v:e[u]){
        dfs(v,mxdep);
        if(dep[v]+1>=mxdep&&u!=1)cur++;
        else dep[u]=max(dep[v]+1,dep[u]);
    }
}
bool check(int mxdep){
    cur=0;
    dfs(1,mxdep);
    if(cur<=k)return true;
    else return false;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&k);
        clear();
        for(int i=2;i<=n;i++){
            int x;
            scanf("%d",&x);
            e[x].push_back(i);
        }
        int l=1,r=n;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid))r=mid-1,ans=min(ans,mid);
            else l=mid+1;
        }
        printf("%d\n",ans);
	}


	return 0;
}
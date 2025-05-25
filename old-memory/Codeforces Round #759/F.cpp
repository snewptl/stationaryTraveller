#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e6+5;
const ll mod=998244353;
const double eps=1e-10;
int n,q;
int a[maxn];
vector<int>e[maxn];
struct qu{
	int l,k,idx;
};
vector<qu>opt[maxn];
int p[maxn],rk[maxn],cnt[maxn],lb[maxn];
int ans[maxn];
void dfs(int u){
	int idx=lb[cnt[a[u]]+1]-1;
	int to=p[idx];
	swap(p[idx],p[rk[u]]);
	swap(rk[u],rk[to]);
	lb[cnt[a[u]]+1]--;
	cnt[a[u]]++;
	for(auto &x:opt[u]){
		int pos=lb[x.l]+x.k-1;
		if(pos>n)ans[x.idx]=-1;
		else ans[x.idx]=p[pos];
	}
	for(auto v:e[u]){
		dfs(v);
	}
	cnt[a[u]]--;
	lb[cnt[a[u]]+1]++;	
	swap(rk[u],rk[to]);
	swap(p[idx],p[rk[u]]);
}
void init(){
	for(int i=1;i<=n;i++)e[i].clear(),opt[i].clear();
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&q);
		init();
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=2;i<=n;i++){
			int u;scanf("%d",&u);
			e[u].push_back(i);
		}
		for(int i=1;i<=n;i++)p[i]=i,rk[i]=i,lb[i]=n+1;
		for(int i=1;i<=q;i++){
			int v,l,k;
			scanf("%d%d%d",&v,&l,&k);
			opt[v].push_back({l,k,i});
		}
		dfs(1);
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		printf("\n");
	}


	return 0;
}
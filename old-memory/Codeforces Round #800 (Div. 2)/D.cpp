#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,cnt;
vector<int>e[maxn];
ll l[maxn],r[maxn];
ll sum[maxn];
void init(){
	cnt=0;
	for(int i=1;i<=n;i++)e[i].clear();
}
void dfs(int u){
	sum[u]=0;
	for(auto v:e[u]){
		dfs(v);
		sum[u]+=sum[v];
	}
	sum[u]=min(sum[u],r[u]);
	if(sum[u]<l[u]){
		cnt++;
		sum[u]=r[u];
	}
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){	
		scanf("%d",&n);
		init();
		for(int i=2;i<=n;i++){
			int x;scanf("%d",&x);
			e[x].push_back(i);
		}
		for(int i=1;i<=n;i++){
			scanf("%lld%lld",&l[i],&r[i]);
		}
		dfs(1);
		printf("%d\n",cnt);
	}


	return 0;
}
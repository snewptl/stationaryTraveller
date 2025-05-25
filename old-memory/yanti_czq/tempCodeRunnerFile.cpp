#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,col[maxn];
vector<int>e[maxn];
int dfn[maxn],tot;
void dfs(int u,int p){
	dfn[u]=++tot;
	int cnt=0;
	for(auto v:e[u]){
		if(v==p)continue;
		if(dfn[v]){
			if(col[u]==col[v])cnt++;
			continue;
		}
		col[v]=col[u]^1;
		dfs(v,u);
	}
	if(cnt=2)col[u]^=1;
}
void init(){
	tot=0;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<=n;i++)dfn[i]=0;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=m;i++){
			int u,v;
		
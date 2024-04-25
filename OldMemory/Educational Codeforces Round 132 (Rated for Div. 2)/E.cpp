#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
vector<int>e[maxn];
set<int>s[maxn];
set<int>*pt[maxn];
int n,a[maxn],dp[maxn],ans;
void dfs(int u,int p){
	int flag=0;
	for(auto v:e[u]){
		if(v==p)continue;
		dfs(v,u);
		if(pt[v]->empty())continue;
		if((pt[u]->size())<(pt[v]->size())){
			swap(pt[u],pt[v]);
			swap(dp[u],dp[v]);
		}
		for(auto it:*pt[v]){
			if((!flag)&&(pt[u]->count(it^a[u]^dp[u]^dp[v])))ans++,flag=1;
			pt[u]->insert(it^dp[u]^dp[v]);
		}
		pt[v]->clear();
	}
	dp[u]^=a[u];
	if((pt[u]->count(dp[u]))&&(!flag))flag=1,ans++;
	pt[u]->insert(a[u]^dp[u]);
	if(flag){
		pt[u]->clear();
		dp[u]=0;
	}
}
void init(){
	for(int i=1;i<=n;i++)pt[i]=&s[i];
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		printf("%d\n",ans);
	}


	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
vector<pii>e[maxn];
int p,n,tot;
int anse[maxn],ansn[maxn],ans;
void dfs(int u,int p){
	for(auto it:e[u]){
		int v=it.first,idx=it.second;
		if(v==p)continue;
		++tot;
		if((ansn[u]&ans)==0){
			anse[idx]=tot;
			ansn[v]=tot+ans;
		}
		else {
			anse[idx]=tot+ans;
			ansn[v]=tot;
		}
		dfs(v,u);

	}
}
void init(){
	for(int i=1;i<=n;i++){
		e[i].clear();
		tot=0;
	}
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&p);
		n=(1<<p);
		init();
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back({v,i});
			e[v].push_back({u,i});
		}
		ans=n;
		ansn[1]=n;
		dfs(1,0);
		printf("%d\n",1);
		for(int i=1;i<=n;i++)printf("%d ",ansn[i]);
		puts("");
		for(int i=1;i<n;i++)printf("%d ",anse[i]);
		puts("");
	}


	return 0;
}
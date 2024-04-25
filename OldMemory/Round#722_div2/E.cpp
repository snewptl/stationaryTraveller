#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+5;
vector<int>e1[maxn],e2[maxn];
int n,dfn,ans;
int le[maxn],ri[maxn];
void dfs1(int u){
	le[u]=++dfn;
	for(auto v:e2[u]){
		dfs1(v);
	}
	ri[u]=dfn;
}
set<pair<int,int>>s;
void dfs2(int u,int sum){
	ans=max(ans,sum);
	for(auto v:e1[u]){
		auto nxt=s.lower_bound({le[v],v});
		auto it=nxt;
		if(it!=s.begin())it--;
		int temp=0;
		if((nxt==s.end()||ri[nxt->second]>ri[v])
			&&(it==nxt||ri[it->second]<ri[v])||(nxt!=s.end()&&ri[it->second]>=ri[nxt->second])){
				temp=1;
		}
		s.insert({le[v],v});
		dfs2(v,sum+temp);
		s.erase({le[v],v});
	}
}
void init(){
	s.clear();
	dfn=ans=0;
	for(int i=1;i<=n;i++){
		e1[i].clear();
		e2[i].clear();
	}

}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);init();
		for(int i=2;i<=n;i++){
			int u;scanf("%d",&u);
			e1[u].push_back(i);
		}
		for(int i=2;i<=n;i++){
			int u;scanf("%d",&u);
			e2[u].push_back(i);
		}
		dfs1(1);
		s.insert({le[1],1});
		dfs2(1,1);
		printf("%d\n",ans);
	}


	return 0;
}
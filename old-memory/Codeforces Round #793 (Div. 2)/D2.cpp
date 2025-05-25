#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
char s[maxn];
int frt[maxn],nxt[maxn],vis[maxn];
set<int>od;
vector<pii>ans;
void init(){
	for(int i=1;i<=n;i++){
		frt[i]=i-1;
		nxt[i]=i+1;
	}
	nxt[n]=1;
	frt[1]=n;
	ans.clear();
	od.clear();
}
void del(int u){
	frt[nxt[u]]=frt[u];
	nxt[frt[u]]=nxt[u];
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		init();
		for(int i=1;i<=n;i++){
			if(s[i]=='1')vis[i]=1,od.insert(i);
			else vis[i]=0;
		}
		if(od.size()==0||od.size()%2!=0)puts("NO");
		else {
			while(od.size()){
				int u=*od.begin();
				od.erase(u);
				del(u);
				int v;
				if(!vis[nxt[u]])v=nxt[u];
				else v=frt[u];
				vis[v]^=1;
				if(vis[v])od.insert(v);
				else if(od.count(v))od.erase(v);
				ans.push_back({u,v});
			}
			puts("YES");
			for(auto it:ans){
				printf("%d %d\n",it.first,it.second);
			}
		}
	}


	return 0;
}
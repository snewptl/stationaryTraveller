#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e3+5;
const ll mod=998244353;
const double eps=1e-10;
int fa[maxn],sz[maxn];
int n,d,cnt=1;
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			fa[i]=i;sz[i]=1;
		}
		int mx=1;
		while(d--){
			int u,v;
			scanf("%d%d",&u,&v);
			int fu=find(u),fv=find(v);
			if(fu!=fv){
				fa[fv]=fu;
				sz[fu]+=sz[fv];
				mx=max(mx,sz[fu]);
			}
			else {
				cnt++;
			}
			vector<int>vec;
			for(int i=1;i<=n;i++){
				if(fa[i]!=i)continue;
				vec.push_back(-sz[i]);
			}
			int res=0;
			sort(vec.begin(),vec.end());
			for(int i=0;i<min((int)vec.size(),cnt);i++){
				res+=-vec[i];
			}
			mx=max(res,mx);
			printf("%d\n",mx-1);
		}
	}


	return 0;
}
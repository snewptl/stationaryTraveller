#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,in[maxn],a[maxn];
vector<pii>e;
int ans;
void init(){
	e.clear();
	for(int i=1;i<=n;i++)in[i]=0;
	ans=2e9;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v)	;
			e.push_back({u,v});
			in[v]++,in[u]++;
		}
		if(m%2==0)ans=0;
		else {
			for(int i=1;i<=n;i++){
				if(in[i]%2)ans=min(ans,a[i]);
			}
			for(int i=0;i<m;i++){
				int u=e[i].first,v=e[i].second;
				if(in[u]%2==0&&in[v]%2==0)ans=min(a[u]+a[v],ans);
			}

		}
		printf("%d\n",ans);


	}


	return 0;
}
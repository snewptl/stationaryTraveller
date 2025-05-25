#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=3e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[maxn],b[maxn],dis[maxn],pa[maxn];
vector<int>e[maxn];
queue<int>q;
void init(){
	for(int i=0;i<=n;i++){
		e[i].clear();
	}
	for(int i=0;i<=n;i++)dis[i]=-1,pa[i]=-1;
}
void bfs(){
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:e[u]){
			if(dis[v]!=-1)continue;
			dis[v]=dis[u]+1;
			pa[v]=u;
			q.push(v);
		}		
	}
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		for(int i=1;i<=n;i++){
			int u=i,v=i-a[i]+b[i-a[i]];
			e[v].push_back(u);
		}
		dis[0]=0;
		q.push(0);
		bfs();
		printf("%d\n",dis[n]);
		if(dis[n]!=-1){
			for(int i=n;i!=-1;i=pa[i]){
				printf("%d ",i-a[i]);
				if(i-a[i]==0)break;
			}
			printf("\n");
		}
	}


	return 0;
}
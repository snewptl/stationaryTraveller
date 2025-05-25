#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int cnt=1,h[maxn];
struct Edge{
	int v,w,next;
}e[maxn<<1];
void add(int u,int v,int w){
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=h[u];
	h[u]=cnt++;
} 
int n;
int dis[maxn],mx[maxn],sec[maxn];
int ans[maxn];
void dfs(int u,int p){
	for(int i=h[u];i;i=e[i].next){
		int v=e[i].v,w=e[i].w;
		if(v==p)continue;
		dis[v]=dis[u]+w;
		dfs(v,u);
		if(mx[v]+w>=mx[u]){
			sec[u]=mx[u];
			mx[u]=mx[v]+w;
		}
		else if(mx[v]+w>sec[u])
			sec[u]=mx[v]+w;
	}
}
void dfs2(int u,int p,int temp){
	for(int i=h[u];i;i=e[i].next){
		int v=e[i].v,temp1;
		if(v==p)continue;
		if(mx[v]+e[i].w==mx[u]){
			temp1=max(sec[u]-dis[u],temp);
			ans[v]=max(temp1,mx[v]-dis[v]);			
		}
		else {
			temp1=max(mx[u]-dis[u],temp);
			ans[v]=temp1;
		}
		dfs2(v,u,temp1);
	}
}
void init(){
	cnt=1;
	for(int i=1;i<=n;i++){
		h[i]=0;
		mx[i]=0;sec[i]=0;
	}
}
int main(){
	while(scanf("%d",&n)!=EOF){
		
		for(int i=2;i<=n;i++){
			int v,w;
			scanf("%d%d",&v,&w);
			add(i,v,w);add(v,i,w);
		}
		dfs(1,0);
		ans[1]=mx[1];
		dfs2(1,0,0);
		for(int i=1;i<=n;i++){
			// printf("%d %d %d\n",ans[i]+dis[i],mx[i],sec[i]);
			printf("%d\n",dis[i]+ans[i]);
		}	
		init();	
	}

	return 0;
}
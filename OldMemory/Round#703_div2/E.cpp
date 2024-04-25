#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int maxn=1e5+10;
int h[maxn*52],cnt=1,cnt1;
struct Edge{
	int v,next,w;
}e[maxn*2*55];
void add(int u,int v,int w){
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=h[u];
	h[u]=cnt++;
}
int n,m;
int vis[maxn*52];
ll dis[maxn*52];

void diji(){
	priority_queue<pii,vector<pii>,greater<pii>>q;
	for(int i=1;i<=n*52+0;i++)dis[i]=1e15;
	q.push(make_pair(0,1));dis[1]=0;
	while(!q.empty()){
		pii p=q.top();q.pop();
		int u=p.second;
		if(dis[u]!=p.first)continue;
		for(int i=h[u];i;i=e[i].next){
			if(i<cnt1)continue;
			int v=e[i].v,w=e[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
int main(){
    scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	cnt1=cnt;
	for(int i=1;i<=n;i++){
		for(int j=h[i];j;j=e[j].next){
			if(j>=cnt1)continue;
			int v=e[j].v,w=e[j].w;
			int k=v*51+w+n;
			add(i,k,0);
			for(int t=h[v];t;t=e[t].next){
				if(t>=cnt1)continue;
				int tv=e[t].v,tw=e[t].w;
				add(k,tv,(tw+w)*(tw+w));
			}
		}
	}
	diji();
	for(int i=1;i<=n;i++){
		if(dis[i]!=1e15)printf("%lld ",dis[i]);
		else printf("-1 ");
	}
    return 0;
}
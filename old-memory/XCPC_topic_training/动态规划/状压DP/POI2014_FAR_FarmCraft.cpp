#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int maxn=5e5+10;
struct Edge{
	int v,next;
}e[maxn<<1];
int cnt=1,h[maxn];
void add(int u,int v){
	e[cnt].v=v;
	e[cnt].next=h[u];
	h[u]=cnt++;
}
int n,c[maxn],size[maxn],t[maxn];
void dfs(int u,int p){
	vector<pii>a;
	size[u]=1;
	for(int i=h[u];i;i=e[i].next){
		int v=e[i].v;
		if(v==p)continue;
		dfs(v,u);
		size[u]+=size[v];
		a.push_back(make_pair(t[v]-2*size[v],v));
	}
	sort(a.begin(),a.end());
	int k=a.size(),mx=0,sum=0;
	for(int i=k-1;i>=0;i--){
		int p=a[i].second;
		mx=max(mx,t[p]+sum+1);
		sum+=size[p]*2;
	}
	if(u!=1)t[u]=max(mx,c[u]);
	else t[u]=max((n-1)*2+c[1],mx);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}		
	dfs(1,0);
	printf("%d\n",t[1]);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int h[maxn],cnt=1;
struct Edge{
	int v,next;
}e[maxn<<1];
void add(int u,int v){
	e[cnt].v=v;
	e[cnt].next=h[u];
	h[u]=cnt++;
}
int n,pos,sgn;
int dep[maxn],vis[maxn<<1],sum[maxn];
int f[50];
void init(){
	f[0]=f[1]=1;
	for(int i=2;i<=27;i++){
		f[i]=f[i-1]+f[i-2];
	}
}
void dfs(int u,int p){
	sum[u]=1;
	for(int i=h[u];i;i=e[i].next){
		int v=e[i].v;
		if(v==p||vis[i])continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		sum[u]+=sum[v];
	}
}
void dfs2(int rt,int p,int k){
	if(pos)return;
	for(int i=h[rt];i;i=e[i].next){
		int v=e[i].v;
		if(v==p||vis[i])continue;
		if(sum[v]==f[k]){
			pos=v;sgn=0;
			vis[i]=1;
		}
		else if(sum[v]==f[k+1]){
			pos=v;sgn=1;
			vis[i]=1;
		}	
		dfs2(v,rt,k);
	}
}
bool find(int rt,int k){
	if(k==0||k==1||k==2)return true;
	pos=0,sgn=0;
	dfs2(rt,0,k-2);
	int memp=pos,memsgn=sgn;
	if(!memp)return false;
	dep[memp]=dep[rt]=0;
	dfs(memp,0);dfs(rt,0);
	if(memsgn){
		if(find(memp,k-1)&&find(rt,k-2))return true;
		else return false;
	}
	else {
		if(find(memp,k-2)&&find(rt,k-1))return true;
		else return false;
	}
}
bool check(int rt,int tot){
	int k=0;
	for(k=0;k<=27;k++){
		if(f[k]==tot)break;
	}
	if(k==28)return false;
	if(find(rt,k))return true;
	else return false;
}
int main(){
	
    scanf("%d",&n);init();
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs(1,0);
	if(check(1,n))printf("YES\n");
	else printf("NO\n");
    return 0;
}
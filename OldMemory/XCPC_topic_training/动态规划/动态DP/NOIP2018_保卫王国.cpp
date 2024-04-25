#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const ll inf=1e10+5;
int n,m,cnt;
char s[maxn];
vector<int>e[maxn];
ll a[maxn],g[maxn][2],f[maxn][2];
int sz[maxn],son[maxn],top[maxn],fa[maxn],rk[maxn],dfn[maxn],ed[maxn];
struct mat{
	ll g[2][2];
	mat(){
		for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			g[i][j]=1e17;
	}
	const mat operator*(const mat &b) const{
		mat c;
		for(int i=0;i<2;i++)
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				c.g[i][j]=min(c.g[i][j],g[i][k]+b.g[k][j]);
			}
		}
		return c;
	}
}t[maxn<<2];
void push_up(int rt){
	t[rt]=t[rt<<1|1]*t[rt<<1];
}
void init(int rt,int p){
	t[rt].g[0][1]=t[rt].g[1][1]=g[p][1];
	t[rt].g[1][0]=g[p][0];
}
void build(int rt,int l,int r){
	if(l==r){
		init(rt,rk[l]);
		return;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	push_up(rt);
}
void dfs1(int u,int p){
	sz[u]=1;
	for(auto v:e[u]){
		if(v==p)continue;
		dfs1(v,u);
		fa[v]=u;
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
void dfs2(int u,int pre,int p){
	dfn[u]=++cnt;rk[cnt]=u;
	top[u]=pre;g[u][1]=a[u];
	if(son[u])dfs2(son[u],pre,u);
	else ed[pre]=u;
	for(auto v:e[u]){
		if(v==p||v==son[u])continue;
		dfs2(v,v,u);
		g[u][1]+=min(f[v][1],f[v][0]);
		g[u][0]+=f[v][1];
	}
	f[u][1]=min(f[son[u]][0],f[son[u]][1])+g[u][1];
	f[u][0]=g[u][0]+f[son[u]][1];
}
void modify(int rt,int l,int r,int p){
	if(l==r){
		init(rt,p);
		return ;
	}
	int mid=l+r>>1;
	if(dfn[p]<=mid)modify(rt<<1,l,mid,p);
	else modify(rt<<1|1,mid+1,r,p);
	push_up(rt);
}
mat query(int rt,int l,int r,int xl,int xr){
	if(xl==l&&xr==r){
		return t[rt];
	}
	int mid=l+r>>1;
	mat x;x.g[0][0]=x.g[1][1]=0;
	if(xr>mid)x=x*query(rt<<1|1,mid+1,r,max(mid+1,xl),xr);
	if(xl<=mid)x=x*query(rt<<1,l,mid,xl,min(xr,mid));
	return x;
}
void change(int p){
	while(p){
		modify(1,1,cnt,p);
		p=top[p];
		mat x;x.g[0][0]=x.g[0][1]=0;
		x=x*query(1,1,cnt,dfn[p],dfn[ed[p]]);
		if(fa[p]){
			g[fa[p]][0]+=x.g[0][1]-f[p][1];
			g[fa[p]][1]+=min(x.g[0][0],x.g[0][1])-min(f[p][0],f[p][1]);
		}
		f[p][0]=x.g[0][0],f[p][1]=x.g[0][1];
		p=fa[p];
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0);dfs2(1,1,0);
	build(1,1,cnt);
	while(m--){
		int p1,p2,w1,w2;
		scanf("%d%d%d%d",&p1,&w1,&p2,&w2);
		ll temp1[2],temp2[2];
		for(int i=0;i<2;i++)temp1[i]=g[p1][i];
		if(!w1)g[p1][1]+=inf;else g[p1][0]+=inf;
		change(p1);
		for(int i=0;i<2;i++)temp2[i]=g[p2][i];
		if(!w2)g[p2][1]+=inf;else g[p2][0]+=inf;
		change(p2);
		mat x;x.g[0][0]=x.g[0][1]=0;
		x=x*query(1,1,n,dfn[1],dfn[ed[1]]);
		ll ans=min(x.g[0][0],x.g[0][1]);
		if(ans<inf)printf("%lld\n",ans);
		else printf("-1\n");
		for(int i=0;i<2;i++)g[p2][i]=temp2[i];
		change(p2);
		for(int i=0;i<2;i++)g[p1][i]=temp1[i];
		change(p1);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e5+10;
int h[maxn],cnt=1;
struct Edge{
	int next,v;
}e[maxn<<1];
void add(int u,int v){
	e[cnt].v=v;
	e[cnt].next=h[u];
	h[u]=cnt++;
}
int n,k;
int sz[maxn];
int f[maxn][105][2][2];// f[][][picked][seen]
ll g[105][2][2];
void dfs2(int u,int p){
	f[u][1][1][0]=1,f[u][0][0][0]=1;
	sz[u]=1;
	for(int i=h[u];i;i=e[i].next){
		int v=e[i].v;
		if(v==p)continue;
		dfs2(v,u);
		for(int j=0;j<=min(sz[u],k);j++){
			for(int x=0;x<2;x++)
			for(int y=0;y<2;y++)
			g[j][x][y]=f[u][j][x][y],f[u][j][x][y]=0;	
		}
		for(int j=0;j<=min(sz[u],k);j++){
			for(int t=0;t<=min(sz[v],k-j);t++){
				f[u][t+j][0][0]+=(1LL*g[j][0][0]*f[v][t][0][1])%mod,f[u][t+j][0][0]%=mod;
				f[u][t+j][0][1]+=(1LL*g[j][0][0]*f[v][t][1][1]+g[j][0][1]*(f[v][t][0][1]+f[v][t][1][1]))%mod,f[u][t+j][0][1]%=mod;
				f[u][t+j][1][0]+=(1LL*g[j][1][0]*(f[v][t][0][0]+f[v][t][0][1]))%mod,f[u][t+j][1][0]%=mod;
				f[u][t+j][1][1]+=(1LL*g[j][1][0]*(f[v][t][1][0]+f[v][t][1][1])+g[j][1][1]*(1LL*f[v][t][0][0]+f[v][t][0][1]+f[v][t][1][0]+f[v][t][1][1]))%mod,f[u][t+j][1][1]%=mod;					
			}	
		}	
		sz[u]+=sz[v];		
	}	

}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs2(1,0);
	printf("%lld\n",(1LL*f[1][k][0][1]+f[1][k][1][1])%mod);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,l,r,sonl;
vector<int>e[maxn];
ll sz[maxn],ans[maxn],sum;
ll vis[maxn];
int fa[maxn][20],dep[maxn];
void dfs1(int u,int p){
	sz[u]=1;
	fa[u][0]=p;
	for(auto v:e[u]){
		if(v==p)continue;
		dep[v]=dep[u]+1;
		dfs1(v,u);
		sz[u]+=sz[v];
	}
}
bool find(int top,int x){
	for(int i=19;i>=0;i--){
		if(fa[x][i]!=-1&&dep[fa[x][i]]>=dep[top])
			x=fa[x][i];
	}
	if(x==top)return true;
	else return false;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			e[i].clear();
			ans[i]=0;vis[i]=0;
			for(int j=0;j<20;j++)fa[i][j]=-1;
		}
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		sum=1LL*n*(n-1)/2;
		dep[0]=1;
		dfs1(0,-1);
		for(int j=1;j<20;j++){
			for(int i=0;i<n;i++){
				if(fa[i][j-1]!=-1)
				fa[i][j]=fa[fa[i][j-1]][j-1];
			}
			
		}
		for(auto x:e[0]){
			ans[0]+=(sz[x]-1)*sz[x]/2;
		}
		sum-=ans[0];
		l=r=0;vis[0]=1;
		for(int i=1;i<n;i++){
			if(!sum)break;
			if(vis[i])continue;
			if(find(l,i)){
				for(int j=i;j!=l;j=fa[j][0]){
					vis[j]=1;
					if(dep[j]==2)sonl=j;
				}
				l=i;
			}
			else if(find(r,i)&&!find(sonl,i)){
				for(int j=i;j!=r;j=fa[j][0]){
					vis[j]=1;
				}
				r=i;
			}
			else ans[i]=sum,sum=0;
			if(sum){
				ll temp;
				if(!r)temp=sz[l]*(sz[r]-sz[sonl]);
				else temp=sz[l]*sz[r];
				ans[i]=sum-temp;
				sum=temp;			
			}

		}
		ans[n]=sum;
		for(int i=0;i<=n;i++){
			printf("%lld ",ans[i]);
		}
		printf("\n");

    }


    return 0;
}
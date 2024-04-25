#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=6e2+5;
int n,m;
ll dis[maxn],link[maxn][maxn];
int vis[maxn];
int main(){
	scanf("%d%d",&n,&m);
	memset(link,0x3f,sizeof(link));
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		link[u][v]=min(link[u][v],1LL*w);
	}	
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		for(int j=0;j<n;j++)
			dis[j]=link[i][j];
		int cnt=0;
		while(cnt<n){
			ll mn=1e18,cur;
			for(int j=0;j<n;j++){
				if(vis[j])continue;
				if(mn>dis[j]){
					mn=dis[j];
					cur=j;
				}
			}
			cnt++;vis[cur]=1;
			for(int j=0;j<n;j++){
				dis[(j+dis[cur])%n]=min(dis[(j+dis[cur])%n],dis[cur]+link[cur][j]);
			}
			dis[(cur+1)%n]=min(dis[(cur+1)%n],dis[cur]+1);
		}
		dis[i]=0;
		for(int j=0;j<n;j++)printf("%lld ",dis[j]);
		printf("\n");
	}
	return 0;
}
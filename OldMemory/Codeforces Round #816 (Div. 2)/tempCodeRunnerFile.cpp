#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,q;
vector<pii>e[maxn];
int vis[35][maxn];
int ans[maxn];
int mi[35];
int main(){
	int T=1;//scanf("%d",&T);
    mi[0]=1;
    for(int i=1;i<=30;i++)mi[i]=mi[i-1]*2;
	while(T--){
        scanf("%d%d",&n,&q);
        for(int i=1;i<=q;i++){
            int u,v,x;
            scanf("%d%d%d",&u,&v,&x);
            e[u].push_back({v,x});
            e[v].push_back({u,x});
        }
        for(int u=1;u<=n;u++){
            for(int i=29;i>=0;i--){
                int cur=mi[i];
                for(auto p:e[u]){
                    int v=p.first,w=p.second;
                    if((w&cur)==0){
                        vis[i][u]=vis[i][v]=1;
                    }
                    else if(u==v)vis[i][u]=1,ans[u]|=cur;
                }               
            }
        }
        for(int u=1;u<=n;u++){
            for(int i=29;i>=0;i--){
                int cur=mi[i];
                if(vis[i][u])continue;
                for(auto p:e[u]){
                    int v=p.first,w=p.second;
                    if((w&cur)&&u!=v){
                        int flag=1;
                        if(vis[i][v]==1&&((ans[u]&cur)==0))flag=0;
                        if(!flag)ans[i]|=cur;
                    }
                }               
            }
        }        
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
        printf("\n");
	}
	return 0;
}
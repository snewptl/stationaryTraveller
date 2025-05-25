#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
typedef pair<int,int>pii;
struct Edge{
	int nxt,w,v;
}e[maxn<<1];
int h[maxn],cnt=1;
void add(int u,int v,int w){
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].nxt=h[u];
	h[u]=cnt++;
}
int n,m,k;
// priority_queue<pii,vector<pii>,greater<pii>>q;
int dis[250005][25];
int ans[505][505];
int dep[250005];
struct Node{
	int val;
	int pos;
	int dep;
};
priority_queue<Node,vector<Node>,greater<Node>>q;
void diji(int p){
	for(int i=max(0,p/m-k);i<=min(p/m+k,n-1);i++){
		for(int j=max(0,p%m-k);i<=min(p%m+k,m-1);j++){
			for(int t=0;t<k;t++)
			dis[i*m+j][t]=1e9;
		}
	}
	dis[p][0]=0;
	Node st;st.val=0;st.dep=0;st.pos=p;
	q.push(st);
	while(!q.empty()){
		int u=q.top().pos;
		int dist=q.top().val;
		int depth=q.top().dep;
		q.pop();
		if(dis[u][depth]!=dist)continue;
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].v;
			int w=e[i].w;
			int temp=abs(v/m-p/m)+abs(v%m-p%m);
			if(temp>k)continue;
			ans[p/m][p%m]=min(ans[p/m][p%m])
			if(dis[v][depth+1]>dis[u][depth]+w){
				dis[v][depth+1]=dis[u][depth]+w;
				Node ed;
				ed.pos=v;ed.dep=depth+1;
				ed.val=dis[v][depth+1];
			}
		}
	}
}
int main(){
    int T=1;
    while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m-1;j++){
				int w;scanf("%d",&w);
				add(i*m+j,i*m+j+1,w);
				add(i*m+j+1,i*m+j,w);
			}
		}
		for(int i=0;i<n-1;i++){
			for(int j=0;j<m;j++){
				int w;scanf("%d",&w);
				add(i*m+j,(i+1)*m+j,w);
				add((i+1)*m+j,i*m+j,w);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)ans[i][j]=1e9;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				diji(i*m+j);
				if(ans[i][j]!=1e9&&k%2==0)printf("%d ",ans[i][j]*2);
				else printf("-1\n");
			}
			printf("\n");
		}

		
    }	
    return 0;
}
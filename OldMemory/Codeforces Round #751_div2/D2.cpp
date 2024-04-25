#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=3e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[maxn],b[maxn],dis[maxn],pa[maxn],vis[maxn];
vector<int>e[maxn];
queue<int>q;
struct Tree{
	int sum,tag;
}t[maxn<<2];
void init(){
	for(int i=0;i<=n;i++){
		e[i].clear();
	}
	for(int i=0;i<=n;i++)dis[i]=-1,pa[i]=-1,vis[i]=1;
}
void push_up(int rt){
	t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum;
}
void build(int rt,int l,int r){
	int mid=l+r>>1;
	if(l==r){
		t[rt].tag=0;
		t[rt].sum=vis[l];
		return ;
	}
	t[rt].tag=0;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	push_up(rt);
}
int find(int rt,int l,int r,int xl,int xr){
	int mid=l+r>>1;
	if(l==r){
		if(t[rt].sum)return l;
		else return -1;
	}
	int res=-1;
	if(xl<=mid){
		if(t[rt<<1].sum)
			res=find(rt<<1,l,mid,xl,min(xr,mid));
	}
	if(res==-1){
		if(xr>mid&&t[rt<<1|1].sum)
			res=find(rt<<1|1,mid+1,r,max(mid+1,xl),xr);
	}
	return res;
}
void update(int rt,int l,int r,int xp){
	int mid=l+r>>1;
	if(l==r){
		t[rt].sum=0;
		return ;
	}
	if(xp<=mid)update(rt<<1,l,mid,xp);
	else update(rt<<1|1,mid+1,r,xp);
	push_up(rt);
}
void bfs(){
	while(!q.empty()){
		int u=q.front();q.pop();
		
		while(true){
			int cur=find(1,0,n,u-a[u],u);
			if(cur==-1)break;
			cur+=b[cur];
			if(dis[cur]==-1)q.push(cur);
			dis[cur]=dis[u]+1;
			pa[cur]=u;
			for(auto v:e[cur]){
				if(vis[v])continue;
				vis[v]=0;
				update(1,0,n,v);
				if(v!=1)printf("%d\n",v);
				
			}
		}	
	}
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		for(int i=1;i<=n;i++){
			int u=i,v=i+b[i];
			e[v].push_back(u);
		}
		e[0].push_back(0);
		build(1,0,n);
		dis[n]=0;
		q.push(n);
		for(auto v:e[n]){
			if(vis[n])continue;
			vis[v]=0;
			update(1,0,n,v);
		}
		bfs();
		printf("%d\n",dis[0]);
		// if(!vis[0]){
		// 	vector<int>vec;
		// 	for(int i=pa[0];;i=pa[i]){
		// 		vec.push_back(i);
		// 		printf("%d ",i);
		// 		if(i==0)break;
		// 		if(i==n)break;
		// 	}
		// 	reverse(vec.begin(),vec.end());
		// 	for(auto x:vec)printf("%d ",x-a[x]);
		// 	printf("\n");
		// }
		
	}


	return 0;
}
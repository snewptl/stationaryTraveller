#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
typedef long long ll;
typedef pair<int,int>pii;
int n,q;
int a[4][maxn];
ll pre[4][maxn];
vector<pii>vec[maxn];
struct node{
	ll v1,v2,v3;
}t[maxn<<2];
void push_up(int rt){
	t[rt].v1=max(t[rt<<1].v1,t[rt<<1|1].v1);
	t[rt].v2=max(t[rt<<1].v2,t[rt<<1|1].v2);
	t[rt].v3=max(t[rt<<1].v1+t[rt<<1|1].v2,max(t[rt<<1].v3,t[rt<<1|1].v3));
}
void build(int rt,int l,int r){
	int mid=l+r>>1;
	if(l==r){
		t[rt].v1=pre[1][l]-pre[2][l-1];
		t[rt].v2=pre[3][n]-pre[3][r-1]+pre[2][r];
		t[rt].v3=t[rt].v1+t[rt].v2;
		return ;
	}
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	push_up(rt);
}

void update(int rt,int l,int r,int p,ll x){
	int mid=l+r>>1;
	if(l==r){
		t[rt].v1=max(t[rt].v1,x);
		t[rt].v3=t[rt].v1+t[rt].v2;
		return ;
	}
	if(p<=mid)update(rt<<1,l,mid,p,x);
	else update(rt<<1|1,mid+1,r,p,x);
	push_up(rt);
}
node mg(node x,node y){
	node cur;
	cur.v1=max(x.v1,y.v1);
	cur.v2=max(x.v2,y.v2);
	cur.v3=max(max(x.v3,y.v3),x.v1+y.v2);
	return cur;
}
node query(int rt,int l,int r,int xl,int xr){
	int mid=l+r>>1;
	if(xl==l&&r==xr)
		return t[rt];
	node cur,ls,rs;
	if(xl<=mid){
		ls=query(rt<<1,l,mid,xl,min(xr,mid));
		cur=ls;
	}
	if(xr>mid){
		rs=query(rt<<1|1,mid+1,r,max(mid+1,xl),xr);
		if(xl<=mid)cur=mg(cur,rs);
		else cur=rs;
	}
	return cur;
}

ll ans;

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=3;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			pre[i][j]=pre[i][j-1]+a[i][j];
		}
	}
	build(1,1,n);
	for(int i=1;i<=q;i++){
		int l,r,k;
		scanf("%d %d %d",&l,&r,&k);
		vec[r].push_back({l,k});
	}
	ans=-1e18;
	for(int i=1;i<=n;i++){
		for(auto p:vec[i]){
			int l=p.first,k=p.second;
			node cur=query(1,1,n,l,i);
			if(i<n)update(1,1,n,i+1,cur.v1-k);
			ans=max(ans,cur.v3-k);
			// printf("%lld %lld %lld\n",cur.v1,cur.v2,cur.v3);
		}
	}
	printf("%lld\n",ans);
	
	return  0;
}
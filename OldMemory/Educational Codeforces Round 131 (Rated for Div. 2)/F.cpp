#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef array<array<ll,3>,3> mat33;
typedef array<ll,3> mat31;
typedef double db;
const int maxn=2e5+5;
const int border=2e5;
const ll mod=998244353;
const double eps=1e-10;
mat33 add,del,e;
mat31 in,out;
int q,d;
int vis[maxn]; 
struct Tree{
	mat33 tag;
	mat31 f;
}t[maxn<<2];
mat33 mul33(mat33 a,mat33 b){
	mat33 c;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			ll res=0;
			for(int k=0;k<3;k++){
				res+=a[i][k]*b[k][j];
			}
			c[i][j]=res;
		}
	}
	return c;
}
mat31 mul31(mat33 a,mat31 b){
	mat31 c;
	for(int i=0;i<3;i++){
		ll res=0;
		for(int j=0;j<3;j++){
			res+=a[i][j]*b[j];
		}
		c[i]=res;
	}
	return c;
}

void push_up(int rt){
	for(int i=0;i<3;i++){
		t[rt].f[i]=t[rt<<1].f[i]+t[rt<<1|1].f[i];
	}
}
void push_dn(int rt){
	t[rt<<1].f=mul31(t[rt].tag,t[rt<<1].f);
	t[rt<<1].tag=mul33(t[rt].tag,t[rt<<1].tag);
	t[rt<<1|1].f=mul31(t[rt].tag,t[rt<<1|1].f);
	t[rt<<1|1].tag=mul33(t[rt].tag,t[rt<<1|1].tag);
	t[rt].tag=e;
}
void build(int rt,int l,int r){
	int mid=l+r>>1;
	t[rt].tag=e;
	if(l==r)return;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void update33(int rt,int l,int r,int xl,int xr,mat33 x){
	int mid=l+r>>1;
	if(xl==l&&xr==r){
		t[rt].tag=mul33(x,t[rt].tag);
		t[rt].f=mul31(x,t[rt].f);	
		return;
	}
	push_dn(rt);
	if(mid>=xl)update33(rt<<1,l,mid,xl,min(xr,mid),x);
	if(xr>mid)update33(rt<<1|1,mid+1,r,max(mid+1,xl),xr,x);
	push_up(rt);
}
void update31(int rt,int l,int r,int xp){
	int mid=l+r>>1;
	if(l==r){
		if(vis[l])t[rt].f=mul31(t[rt].tag,in);
		else t[rt].f=out;
		return;
	}
	push_dn(rt);
	if(xp<=mid)update31(rt<<1,l,mid,xp);
	else update31(rt<<1|1,mid+1,r,xp);
	push_up(rt);
}
int main(){
	add[0][0]=1,add[0][1]=2,add[0][2]=1;
	add[1][1]=1,add[1][2]=1;
	add[2][2]=1;
	del[0][0]=1,del[0][1]=-2,del[0][2]=1;
	del[1][1]=1,del[1][2]=-1;
	del[2][2]=1;
	for(int i=0;i<3;i++)e[i][i]=1;
	in[2]=1;
	scanf("%d%d",&q,&d);
	build(1,1,border);
	while(q--){
		int x;scanf("%d",&x);
		if(vis[x]){
			vis[x]=0;
			if(x>1)update33(1,1,border,max(1,x-d),x-1,del);
			update31(1,1,border,x);
		}
		else {
			vis[x]=1;
			if(x>1)update33(1,1,border,max(1,x-d),x-1,add);
			update31(1,1,border,x);
		}
		printf("%lld\n",(t[1].f[0]-t[1].f[1])/2);
	}


	return 0;
}
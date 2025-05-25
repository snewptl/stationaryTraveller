#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const ll inf=1e18;
int n,q;
ll a[maxn];
ll l,r;
struct Mat{
	ll mat[3][3];
	Mat(){
		for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			mat[i][j]=-inf;
	}
	const Mat operator*(const Mat &b) const {
		Mat c;
		for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				c.mat[i][j]=max(c.mat[i][j],mat[i][k]+b.mat[k][j]);
			}
		}
		return c;
	}
}t[maxn<<2];
void push_up(int rt){
	t[rt]=t[rt<<1]*t[rt<<1|1];
}
void build(int rt,int l,int r){
	if(l==r){
		t[rt].mat[0][0]=a[l];
		t[rt].mat[0][1]=a[l];
		t[rt].mat[1][1]=0;
		t[rt].mat[2][0]=a[l];
		t[rt].mat[2][1]=a[l];
		t[rt].mat[2][2]=0;
		return ;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	push_up(rt);
}
void modify(int rt,int l,int r,int p){
	if(l==r){
		t[rt].mat[0][0]=a[l];
		t[rt].mat[0][1]=a[l];
		t[rt].mat[2][0]=a[l];
		t[rt].mat[2][1]=a[l];
		return ;
	}
	int mid=l+r>>1;
	if(p<=mid)modify(rt<<1,l,mid,p);
	else modify(rt<<1|1,mid+1,r,p);
	push_up(rt);
}
Mat query(int rt,int l,int r,int xl,int xr){
	if(l==xl&&r==xr){
		return t[rt];
	}
	int mid=l+r>>1;
	Mat x;
	for(int i=0;i<3;i++)
		x.mat[i][i]=0;
	if(xl<=mid)x=x*query(rt<<1,l,mid,xl,min(xr,mid));
	if(xr>mid)x=x*query(rt<<1|1,mid+1,r,max(mid+1,xl),xr);
	return x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,1,n);
	scanf("%d",&q);
	while(q--){
		int opt;
		scanf("%d%lld%lld",&opt,&l,&r);
		if(!opt){
			a[l]=r;
			modify(1,1,n,l);
		}	
		else{
			Mat ans;
			ans.mat[0][2]=0;
			ans=ans*query(1,1,n,l,r);
			printf("%lld\n",ans.mat[0][1]);
		}
	}
	return 0;
}
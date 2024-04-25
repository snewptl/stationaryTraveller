#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e4+10;
int n,k,now;
int a[maxn],lst[maxn],le[maxn];
int dp[maxn][105];
struct Tree{
	int val,tag;
}t[maxn<<2];
void push_up(int rt){
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
}
void push_down(int rt){
	t[rt<<1].tag+=t[rt].tag;
	t[rt<<1|1].tag+=t[rt].tag;
	t[rt<<1].val+=t[rt].tag;
	t[rt<<1|1].val+=t[rt].tag;
	t[rt].tag=0;
}
void build(int rt,int l,int r){
	if(l==r){
		t[rt].val=dp[l][now-1];
		t[rt].tag=0;
		return ;
	}
	int mid=l+r>>1;
	t[rt].tag=0,t[rt].val=0;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	push_up(rt);
}
void update(int rt,int l,int r,int xl,int xr,int add){
	if(xl==l&&xr==r){
		t[rt].val+=add;
		t[rt].tag+=add;
		return;
	}
	int mid=l+r>>1;
	push_down(rt);
	if(xl<=mid)update(rt<<1,l,mid,xl,min(mid,xr),add);
	if(xr>mid)update(rt<<1|1,mid+1,r,max(mid+1,xl),xr,add);
	push_up(rt);
}
int query(int rt,int l,int r,int xl,int xr){
	if(xl==l&&xr==r){
		return t[rt].val;
	}
	int ans=1e9,mid=l+r>>1;
	push_down(rt);
	if(xl<=mid)ans=min(ans,query(rt<<1,l,mid,xl,min(mid,xr)));
	if(xr>mid)ans=min(ans,query(rt<<1|1,mid+1,r,max(mid+1,xl),xr));
	return ans;
}
int main(){
    int T=1;
    while(T--){
        scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			le[i]=lst[a[i]];
			lst[a[i]]=i;
		}
		for(int i=1;i<=n;i++)
			dp[i][1]=dp[i-1][1]+(le[i]?i-le[i]:0);
		for(now=2;now<=k;now++){
			build(1,now-1,n);
			for(int j=now;j<=n;j++){
				if(le[j]>=now){
					update(1,now-1,n,now-1,le[j]-1,j-le[j]);
				}
				dp[j][now]=query(1,now-1,n,now-1,j);
			}
		}
		printf("%d\n",dp[n][k]);
    }


    return 0;
}
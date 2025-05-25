#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,m;
int a[maxn];
map<int,int>ans;
ll sum[maxn];
struct Tree{
	int mx,mn;
}t[maxn*2];
int getmx(int rt,int l,int r,int xl,int xr){
	int mid=l+r>>1;
	if(r<xl||l>xr)return 0;
	if(l>=xl&&r<=xr){
		return t[rt].mx;
	}
	return max(getmx(rt<<1,l,mid,xl,xr),getmx(rt<<1|1,mid+1,r,xl,xr));
}
int getmn(int rt,int l,int r,int xl,int xr){
	int mid=l+r>>1;
	if(r<xl||l>xr)return 1e9;
	if(l>=xl&&r<=xr){
		return t[rt].mn;
	}
	
	return min(getmn(rt<<1,l,mid,xl,xr),getmn(rt<<1|1,mid+1,r,xl,xr));
}
void dfs(int l,int r){
	if(l>r)return;
	ll k=sum[r]-sum[l-1];
	if(k<=1e9)ans[(int)k]=1;
	int mx=getmx(1,1,n,l,r),mn=getmn(1,1,n,l,r);
	// int mn=1e9,mx=0;
	// for(int i=l;i<=r;i++)mx=max(mx,a[i]);
	// for(int i=l;i<=r;i++)mn=min(mn,a[i]);
	int it=upper_bound(a+l,a+r+1,(mx+mn)/2)-a;
	if(it==r+1)return;
	dfs(l,it-1);dfs(it,r);
}
void build(int rt,int l,int r){
	if(l==r){
		t[rt].mn=a[l];
		t[rt].mx=a[l];
		return;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
	t[rt].mx=max(t[rt<<1].mx,t[rt<<1|1].mx);
	t[rt].mn=min(t[rt<<1].mn,t[rt<<1|1].mn);
}
void init(){
	build(1,1,n);
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
		ans.clear();
        scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
		}
		init();
		dfs(1,n);
		for(int i=1;i<=m;i++){
			int opt;
			scanf("%d",&opt);
			if(ans[opt])printf("YES\n");
			else printf("NO\n");
		}
    }


    return 0;
}
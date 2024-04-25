#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
int a[maxn];
int pre[maxn][55],h[maxn],sum[maxn];
int n,q;
struct Tree{
	int x,num;
}t[maxn<<2];
void build(int rt,int l,int r){
	if(l==r){
		t[rt].x=a[l];
		t[rt].num=1;
		return;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	int cnt1=0,cnt2=0;
	for(int i=l;i<=r;i++){
		if(a[i]==t[rt<<1].x)cnt1++;
		if(a[i]==t[rt<<1|1].x)cnt2++;
	}
	if(cnt1>(r-l+1)/2)t[rt].x=t[rt<<1].x,t[rt].num=cnt1;
	if(cnt2>(r-l+1)/2)t[rt].x=t[rt<<1|1].x,t[rt].num=cnt2;
	printf("%d\n",t[rt].x);
}
int find(int p,int x){
	int pos=h[x];
	if(pos<p)return pos;
	for(int i=50;i>=0;i--){
		if(pre[pos][i]>=p)pos=pre[pos][i];
	}
	return pre[pos][0];
}
Tree query(int rt,int l,int r,int xl,int xr){
	if(l==xl&&r==xr){
		return t[rt];
	}
	int mid=l+r>>1;
	Tree t1,t2;
	int flag1=0,flag2=0;
	if(xl<=mid){
		t1=query(rt<<1,l,mid,xl,min(mid,xr));flag1=1;
	}
	if(xr>mid){
		t2=query(rt<<1|1,mid+1,r,max(mid+1,xl),xr);flag2=1;
	}
	if(flag1){
		int st=find(l,t1.x);int ed=find(r+1,t1.x);
		t1.num=sum[ed]-sum[st];
		printf("%d %d %d %d\n",xl,min(mid,xr),t1.num,t1.x);
		if(t1.num>(r-l+1)/2)return t1;
	}
	if(flag2){
		int st=find(l,t2.x);int ed=find(r+1,t2.x);
		t2.num=sum[ed]-sum[st];
		// printf("%d %d %d %d\n",max(mid+1,xl),xr,t2.num,t2.x);
		if(t2.num>(r-l+1)/2)return t2;
	}
	t1.num=0,t1.x=0;
	return t1;
}
int main(){
    scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i][0]=h[a[i]];
		sum[i]=sum[h[a[i]]]+1;
		h[a[i]]=i;
	}
	for(int i=1;i<50;i++){
		for(int j=1;j<=n;j++){
			pre[j][i]=pre[pre[j][i-1]][i-1];
		}
	}
	build(1,1,n);
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		Tree x=query(1,1,n,l,r);
		printf("%d\n",max(2*x.num-(r-l+1),1));
	}

    return 0;
}
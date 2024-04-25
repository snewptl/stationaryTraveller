#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef pair<int,int>pii;
int t[maxn<<2];
int n,m,ans,a[maxn],rk[maxn];
void push_up(int rt){
	t[rt]=max(t[rt<<1],t[rt<<1|1]);
}
void build(int rt,int l,int r){
	int mid=l+r>>1;
	if(l==r){
		t[rt]=n+1;
		return;
	}
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	push_up(rt);
}
void update(int rt,int l,int r,int xp){
	int mid=l+r>>1;
	if(l==r){
		t[rt]=xp;
		return ;
	}
	if(xp<=mid)update(rt<<1,l,mid,xp);
	else update(rt<<1|1,mid+1,r,xp);
	push_up(rt);
}
pii query(int rt,int l,int r,int xl,int xr,int edge){
    int mid=l+r>>1;
    if(xl==xr){
        if(t[rt]>edge)return {t[rt],l};
        else return {0,0};
    }
    pii le={0,0},ri={0,0};
    if(xl<=mid)le=query(rt<<1,l,mid,xl,min(xr,mid),edge);
    if(le.first>edge)return le;
    if(xr>mid)ri=query(rt<<1|1,mid+1,r,max(mid+1,xl),xr,edge);
    return ri;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			rk[a[i]]=i;
		}
		build(1,1,n);
		while(m--){
			int opt,t1,t2;
            scanf("%d",&opt);
			if(opt==1){
				scanf("%d",&t1);
				t1^=ans;
				update(1,1,n,a[t1]);
			}
			else {
				scanf("%d%d",&t1,&t2);
				t1^=ans,t2^=ans;
				ans=query(1,1,n,t2,n,t1).second;
				if(!ans)ans=n+1;
                printf("@@%d\n",ans);
			}
		}		
	}
	return 0;	
}
/*
1
5 9
4 3 1 2 5 
2 1 1
2 2 2
2 6 7
2 1 3
2 6 3
2 0 4
1 5
2 3 7
2 4 3
*/
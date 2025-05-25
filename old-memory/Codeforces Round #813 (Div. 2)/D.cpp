#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
struct Tree{
    int pos;
    int mxidx;
}t[maxn<<2];
int n,a[maxn],k,ans,b[maxn];
void push_up(int rt){
    if(a[t[rt<<1].pos]>a[t[rt<<1|1].pos])t[rt].pos=t[rt<<1|1].pos;
    else t[rt].pos=t[rt<<1].pos;
    if(b[t[rt<<1].mxidx]<b[t[rt<<1|1].mxidx])t[rt].mxidx=t[rt<<1|1].mxidx;
    else t[rt].mxidx=t[rt<<1].mxidx;
}
void build(int rt,int l,int r){
    int mid=l+r>>1;
    if(l==r){
        t[rt].pos=l;
        t[rt].mxidx=l;
        return;
    }
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    push_up(rt);
}
void update1(int rt,int l,int r,int xp){
    int mid=l+r>>1;
    if(l==r){
        a[l]=1e9;
        return;
    }
    if(xp<=mid)update1(rt<<1,l,mid,xp);
    else update1(rt<<1|1,mid+1,r,xp);
    push_up(rt);    
}
void update2(int rt,int l,int r,int xp){
    int mid=l+r>>1;
    if(l==r){
        b[l]=1e9;
        return;
    }
    if(xp<=mid)update2(rt<<1,l,mid,xp);
    else update2(rt<<1|1,mid+1,r,xp);
    push_up(rt);    
}
void update(int x){
    update1(1,1,n,x);
    if(x>1)update2(1,1,n,x-1);
    if(x<n)update2(1,1,n,x+1);
}
int query(int rt,int l,int r,int xl,int xr){
    int mid=l+r>>1;
    if(xl==l&&xr==r){
        return t[rt].pos;
    }
    int posl=0,posr=0;
    if(xl<=mid)posl=query(rt<<1,l,mid,xl,min(mid,xl));
    if(xr>mid)posr=query(rt<<1|1,mid+1,r,max(mid+1,xl),xr);
    if(posl){
        if(!posr)return posl;
        else {
            if(b[posl]<b[posr])return posr;
            else return posl;
        }
    }
    else return posr;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=0;
        }
        a[n+1]=a[0]=0;
        for(int i=1;i<n;i++){
            b[i]=max(a[i+1],b[i]);
        }
        for(int i=2;i<=n;i++){
            b[i]=max(a[i-1],b[i]);
        }
        build(1,1,n);
        while(k--){
            int cur=t[1].pos;
            if(b[t[1].mxidx]<=2*a[cur])update(t[1].mxidx);
            else update(cur);
        }
        ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,min(a[i],a[i+1]));
        }
        printf("%d\n",min(a[t[1].pos]*2,ans));
	}   


	return 0;
}
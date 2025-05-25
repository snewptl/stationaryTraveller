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
}t[maxn<<2];
int n,a[maxn],k,ans;
void push_up(int rt){
    if(a[t[rt<<1].pos]>a[t[rt<<1|1].pos])t[rt].pos=t[rt<<1|1].pos;
    else t[rt].pos=t[rt<<1].pos;
}
void build(int rt,int l,int r){
    int mid=l+r>>1;
    if(l==r){
        t[rt].pos=l;
        return;
    }
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    push_up(rt);
}
void update(int rt,int l,int r,int xp){
    int mid=l+r>>1;
    if(l==r){
        a[l]=1e9;
        return;
    }
    if(xp<=mid)update(rt<<1,l,mid,xp);
    else update(rt<<1|1,mid+1,r,xp);
    push_up(rt);    
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
            if(a[posl]>a[posr])return posr;
            else return posl;
        }
    }
    else return posr;
}
int pre[maxn],nxt[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            pre[i]=0;
            nxt[i]=n+1;
        }
        for(int i=2;i<=n;i++){
            if(a[i]!=a[i-1])pre[i]=i-1;
            else pre[i]=pre[i-1];
        }
        for(int i=n;i>=1;i--){
            if(a[i]==)
        }
        build(1,1,n);
        while(k--){
            int cur=t[1].pos;
            // int le=0,ri=0;
            // if(cur>2)le=query(1,1,n,1,cur-1);    
            // if(cur<n-1)ri=query(1,1,n,cur+1,n);
            // if(!le)swap(le,ri);
            // else if(ri&&a[le]>a[ri])swap(le,ri);
            // if(le&&a[le]<2*a[cur])update(1,1,n,le);
            // else 
            update(1,1,n,cur);
        }
        ans=0;
        int cur=t[1].pos;
        for(int i=1;i<cur-1;i++){
            ans=max(ans,min(min(a[i],a[i+1]),a[cur]*2));
        }
        printf("$$%d\n",ans);
	}   


	return 0;
}
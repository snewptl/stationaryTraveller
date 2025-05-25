#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxn=3e5+5;
const double eps=1e-10;
struct Tree{
    int mx,mn,lazy,sum;
}t[maxn<<2];
int n,a[maxn],rk[maxn];
void push_up(int rt){
    t[rt].mx=max(t[rt<<1].mx,t[rt<<1|1].mx);
    t[rt].mn=min(t[rt<<1].mn,t[rt<<1|1].mn);
    t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum;
}
void build(int rt,int l,int r){
    int mid=l+r>>1;
    t[rt].lazy=0;
    if(l==r){
        t[rt].sum=l;
        t[rt].mx=t[rt].mn=t[rt].sum;
        return;
    }
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    push_up(rt);
}
void push_dn(int rt){
    int cur=t[rt].lazy;
    t[rt].lazy=0;
    t[rt<<1].lazy+=cur;
    t[rt<<1].sum+=cur;
    t[rt<<1].mx+=cur;
    t[rt<<1].mn+=cur;
    t[rt<<1|1].lazy+=cur;
    t[rt<<1|1].sum+=cur;
    t[rt<<1|1].mx+=cur;
    t[rt<<1|1].mn+=cur;
}
void update(int rt,int l,int r,int xl,int xr){
    int mid=l+r>>1;
    if(xl==l&&xr==r){
        t[rt].sum--;
        t[rt].lazy--;
        t[rt].mx--;
        t[rt].mn--;
        return;
    }
    push_dn(rt);
    if(xl<=mid)update(rt<<1,l,mid,xl,min(xr,mid));
    if(xr>mid)update(rt<<1|1,mid+1,r,max(mid+1,xl),xr);
    push_up(rt);
}
pii query(int rt,int l,int r,int xl,int xr){
    int mid=l+r>>1;
    if(xl==l&&xr==r){
        return {t[rt].mn,t[rt].mx};
    }
    push_dn(rt);
    pii res={1e9,1e9};
    if(xl<=mid)res=query(rt<<1,l,mid,xl,min(xr,mid));
    if(xr>mid){
        pii temp=query(rt<<1|1,mid+1,r,max(mid+1,xl),xr);
        if(res.first==1e9)res=temp;
        else {
            res.first=min(res.first,temp.first);
            res.second=max(res.second,temp.second);
        }
    }
    return res;
}
int main(){
    int T=1;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            rk[a[i]]=i;
        }
        build(1,1,n);
        for(int i=1;i<=n;i++){
            if(i-1)update(1,1,n,rk[i-1],n);
            update(1,1,n,rk[i],n);
            int flag=0;
            pii le={0,0},ri={0,0};

            if(rk[i]<n){
                if(rk[i]>1)le=query(1,1,n,1,rk[i]-1);
                if(rk[i]<n)ri=query(1,1,n,rk[i]+1,n);
                if(le.first>0)le.first=0;
                if(le.second<0)le.second=0;
                if(le.first>ri.first)swap(le,ri);
                if(le.second>=ri.first)flag=1;
            }
            if(rk[i]>=3){
                le=query(1,1,n,1,rk[i]-2);
                ri=query(1,1,n,rk[i],rk[i]);
                if(le.first>0)le.first=0;
                if(le.second<0)le.second=0;
                if(le.first>ri.first)swap(le,ri);
                if(le.second>=ri.first)flag=1;
            }
            if(flag)printf("y");
            else printf("n");
        }
        puts("");
    }

    return 0;
}
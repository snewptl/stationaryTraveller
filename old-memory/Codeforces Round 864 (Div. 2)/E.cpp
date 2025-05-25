#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxn=2e5+5;
const int maxm=5e6+5;
const double eps=1e-10;
int tot;
int phi[maxm],pri[maxm],vis[maxm];
void get_phi(){
    phi[1]=1;
    for(int i=2;i<maxm;i++){
        if(!vis[i]){
            pri[++tot]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=tot;j++){
            if(i*pri[j]>=maxm)break;
            vis[i*pri[j]]=1;
            if(i%pri[j]==0){
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
            else phi[i*pri[j]]=phi[i]*(pri[j]-1);
        }
    }
}
int n,m;
int a[maxn];
struct Tree{
    int val,ans,mx;
}t[maxn<<2];

pair<int,pii> lca(int x,int y){
    int cntx=0,cnty=0;
    while(x!=y){
        while(y>x)y=phi[y],cnty++;
        while(y<x)x=phi[x],cntx++;
    }
    return {x,{cntx,cnty}};
}
void push_up(int rt,int l,int r){
    int mid=l+r>>1;
    auto it=lca(t[rt<<1].val,t[rt<<1|1].val);
    t[rt].val=it.first;
    t[rt].ans=t[rt<<1].ans+t[rt<<1|1].ans
        +(mid-l+1)*it.second.first
        +(r-mid)*it.second.second;
    t[rt].mx=max(t[rt<<1].mx,t[rt<<1|1].mx);
}
// void push_dn(int rt){
//     if(t[rt].cnt){
//         t[rt<<1].cnt+=t[rt].cnt;
//         t[rt<<1|1].cnt+=t[rt].cnt;
//         for(int i=1;i<=t[rt].cnt;i++){
//             if(t[rt<<1].val==1)break;
//             t[rt<<1].val=phi[t[rt<<1].val];
//         }
//         for(int i=1;i<=t[rt].cnt;i++){
//             if(t[rt<<1|1].val==1)break;
//             t[rt<<1|1].val=phi[t[rt<<1|1].val];
//         }        
//         t[rt].cnt=0;
//     }
// }
void build(int rt,int l,int r){
    if(l==r){
        t[rt].val=t[rt].mx=a[l];
        t[rt].ans=0;
        return ;
    }
    int mid=l+r>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    push_up(rt,l,r);
}
void update(int rt,int l,int r,int xl,int xr){
    if(l==r){
        t[rt].mx=t[rt].val=phi[t[rt].val];
        t[rt].ans=0;
        return;
    }
    if(t[rt].mx==1)return;
    int mid=l+r>>1;
    if(xl<=mid)update(rt<<1,l,mid,xl,min(xr,mid));
    if(xr>mid)update(rt<<1|1,mid+1,r,max(xl,mid+1),xr);
    push_up(rt,l,r);
}
pii query(int rt,int l,int r,int xl,int xr){
    if(l==xl&&r==xr){
        return {t[rt].val,t[rt].ans};
    }
    int mid=l+r>>1;
    pii le={0,0},ri={0,0};
    if(xl<=mid)le=query(rt<<1,l,mid,xl,min(xr,mid));
    if(xr>mid)ri=query(rt<<1|1,mid+1,r,max(xl,mid+1),xr);
    if(le.first){
        if(ri.first){
            auto temp=lca(le.first,ri.first);
            return {temp.first,
                le.second+ri.second
                +(mid-xl+1)*temp.second.first
                +(xr-mid)*temp.second.second
            };
        }
        else return le;
    }
    else return ri;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    get_phi();
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(m--){
        int opt,l,r;
        cin>>opt>>l>>r;
        if(opt==1){
            update(1,1,n,l,r);
        }
        else {
            cout<<query(1,1,n,l,r).second<<'\n';
        }
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=2e5+5;
int n,q,tot;
ll ans;
int a[maxn],b[maxn];
pii ord[maxn];
int rt[maxn],ls[maxn<<5],rs[maxn<<5];
ll reg[maxn<<5],cap[maxn<<5];
void push_up(int u){
	reg[u]=reg[ls[u]]+reg[rs[u]];
	cap[u]=cap[ls[u]]+cap[rs[u]];
}
int build(int l,int r){
	int u=++tot;
	if(l==r){
		cap[u]=0;
		reg[u]=b[l];
		return u;
	}
	int mid=l+r>>1;
	ls[u]=build(l,mid);
	rs[u]=build(mid+1,r);
	push_up(u);
	return u;
}
int update(int u,int l,int r,int p){
	int v=++tot;
	if(l==r){
		cap[v]=a[l];
		reg[v]=0;
		return v;
	}
	int mid=l+r>>1;
	ls[v]=ls[u],rs[v]=rs[u];
	if(p<=mid)ls[v]=update(ls[u],l,mid,p);
	else rs[v]=update(rs[u],mid+1,r,p);
	push_up(v);
	return v;
}
ll get_sum(int u,int l,int r,int xl,int xr,int t){
	int mid=l+r>>1;
	ll res=0;
	if(xl==l&&xr==r){
		return cap[u]+reg[u]*t;
	}
	if(xl<=mid)res+=get_sum(ls[u],l,mid,xl,min(mid,xr),t);
	if(xr>mid)res+=get_sum(rs[u],mid+1,r,max(xl,mid+1),xr,t);
	return res;
}
int query(int u,int l,int r,int xl,int xr,ll h,int t){
	int mid=l+r>>1;
	int res=0;
	if(xl==xr){
		if(h<cap[u]+reg[u]*t)return 0;
		else return 1;
	}
	ll suml=0,sumr=0,sum=0;
	sum=get_sum(u,l,r,xl,xr,t);
	if(sum<=h)return xr-xl+1; 
	if(xl<=mid){
		suml=get_sum(ls[u],l,mid,xl,min(xr,mid),t);
		if(h<=suml)return query(ls[u],l,mid,xl,min(mid,xr),h,t);
		h-=suml;
		res=mid-xl+1;
	}
	if(xr>mid){
		return query(rs[u],mid+1,r,max(xl,mid+1),xr,h,t)+res;		
	}
	return 0;
}

struct Seg{
	int l,r,lst;
	ll rem;
};
vector<Seg>seg;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		ord[i]={(a[i]-1)/b[i]+1,i};
	}
	sort(ord+1,ord+n+1);
	rt[0]=build(1,n);
	for(int i=1;i<=n;i++)
		rt[i]=update(rt[i-1],1,n,ord[i].second);
	for(int i=n;i>=1;i--)
		seg.push_back({i,i,0,a[i]});
	scanf("%d",&q);
	while(q--){
		int t;ll h;
		scanf("%d%lld",&t,&h);
		while(!seg.empty()){
			auto cur=seg.back();seg.pop_back();
			if(cur.l==cur.r){
				cur.rem=min(1ll*a[cur.l],1ll*b[cur.l]*(t-cur.lst)+cur.rem);
				ll mn=min(h,cur.rem);
				h-=mn,cur.rem-=mn;
				if(cur.rem){
					cur.lst=t;
					seg.push_back(cur);
				}
			}
			else {
				int pos=upper_bound(ord+1,ord+n+1,make_pair(t-cur.lst,n))-ord-1;
				// printf("&&%d %d %d\n",cur.l,cur.r,pos);
				int res=cur.l+query(rt[pos],1,n,cur.l,cur.r,h,t-cur.lst)-1;
				if(res<cur.r){
					Seg x={1,res,t,0ll};
					ll rem=get_sum(rt[pos],1,n,cur.l,res+1,t-cur.lst)-h;
					Seg y={res+1,res+1,t,rem};
					if(res+1<cur.r){
						Seg z={res+2,cur.r,cur.lst,0ll};
						seg.push_back(z);
					}
					seg.push_back(y);
					if(res>=1)seg.push_back(x);
					h=0;
				}
				else h-=get_sum(rt[pos],1,n,cur.l,cur.r,t-cur.lst);
				// printf("##%lld\n",h);
			}
			if(!h)break;
		}
		if(seg.empty()){
			Seg x={1,n,t,0ll};
			seg.push_back(x);
		}
		else if(seg.back().l!=1){
			Seg x={1,seg.back().l-1,t,0ll};
			seg.push_back(x);
		}
		ans+=h;
		// printf("&&%lld %d %d\n",h,seg.size(),(*seg.begin()).rem);

		
	}
	printf("%lld\n",ans);
	return 0;
}
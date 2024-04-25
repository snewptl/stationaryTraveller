#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k,ans,tot,a[maxn];
map<int,int>cnt,rk;
vector<pii>vec;
struct tree{
	int val,sz;
}t[maxn<<2];
void init(){
	cnt.clear();
	rk.clear();
	vec.clear();
	ans=1e9;
}
void push_up(int rt){
	t[rt].sz=t[rt<<1].sz+t[rt<<1|1].sz;
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void build(int rt,int l,int r){
	int mid=l+r>>1;
	if(l==r){
		t[rt].val=vec[l-1].first;
		t[rt].sz=1;
		return;
	}
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	push_up(rt);
}
void update(int rt,int l,int r,int xp){
	int mid=l+r>>1;
	if(l==r){
		t[rt].val=0;
		t[rt].sz=0;
		return;
	}
	if(xp<=mid)update(rt<<1,l,mid,xp);
	else update(rt<<1|1,mid+1,r,xp);
	push_up(rt);	
}
int query(int rt,int l,int r,int x){
	int mid=l+r>>1;
	if(t[rt].val<=x)return t[rt].sz;
	if(l==r)return 0;
	if(t[rt<<1].val>=x)return query(rt<<1,l,mid,x);
	return query(rt<<1|1,mid+1,r,x-t[rt<<1].val)+t[rt<<1].sz;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		tot=cnt.size();
		for(auto it:cnt){
			vec.push_back({it.second,it.first});
		}
		for(int i=1;i<=tot;i++)a[i]=vec[i-1].second;
		sort(a+1,a+tot+1);
		sort(vec.begin(),vec.end());
		for(int i=0;i<vec.size();i++){
			rk[vec[i].second]=i;
		}
		build(1,1,tot);
		int mex,dif,cur,frt=0;
		for(mex=0;mex<=n;mex++){
			int pos=lower_bound(a+1,a+tot+1,mex)-a;
			dif=mex;
			if(pos<=tot&&a[pos]==mex){
				cur=a[pos];
				int num=cnt[cur];
				update(1,1,tot,rk[mex]+1);
				dif+=t[1].sz;
				if(k>=num){
					dif-=query(1,1,tot,k-num);
					ans=min(ans,dif-mex);
				}
			}
			else {
				dif+=t[1].sz;
				dif-=query(1,1,tot,k);
				ans=min(ans,dif-mex);				
				frt++;
				if(k<frt)break;
			}
			
		}
		printf("%d\n",ans);
	}


	return 0;
}
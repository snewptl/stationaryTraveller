#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
vector<int>e[maxn],vec;
int used[maxn];
ll ans;
void dfs(int u){  
	used[u]=1;
	vec.push_back(u);
	for(auto v:e[u]){  	
		if(used[v])continue;
		dfs(v);
	}
}
ll cal(int x){
	return x*(x+1)/2;
}
ll check(int l,int r,int mxl,int mxr){
	ll res=0;
	if(l>r)res=cal(mxl-1)+cal(mxr-mxl-1)+cal(n-mxr);
	else if(mxl>=l&&mxl<=r)return 0;
	else if(mxr>=l&&mxr<=r)return 0;
	else if(mxr<l){
		res=1ll*(l-mxr)*(n-r+1);
	}
	else if(mxl>r){
		res=1ll*l*(mxl-r);
	}
	else {
		res=1ll*(l-mxl)*(mxr-r);
	}
	return res;
}
void solve(){
	int len=vec.size()/2,m=vec.size();
	for(int i=0;i<vec.size();i++){
		int l=n+1,r=0,L=n+1,R=0;
		int posl=i,posr=i,mid=vec[i],mxl=vec[i],mxr=vec[i];
		if(mid>n)mid-=n;
		ans-=(cal(mid-1)+cal(n-mid))*cal(n);
		for(int j=0;j<len;j++){
			if(vec[posl]<=n){
				l=min(l,mxl);
				r=max(r,mxr);
			}
			else {
				L=min(L,mxl-n);
				R=max(R,mxr-n);
			}
			posl--;
			if(posl<0)posl+=vec.size();
			posr++;
			if(posr==vec.size())posr-=vec.size();

			mxl=min(vec[posl],vec[posr]);
			mxr=max(vec[posl],vec[posr]);			

			if(mxl>n){
				ans-=check(L,R,mxl-n,mxr-n)*l*(n-r+1);
			}
			else {
				ans-=check(l,r,mxl,mxr)*L*(n-R+1);		
			}
		}
	}

}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ans=cal(n)*cal(n)*2*n;
		for(int i=1;i<=n*2;i++){
			if(used[i])continue;
			dfs(i);
			solve();
			vec.clear();
		}
		printf("%lld\n",ans/2);


	}


	return 0;
}
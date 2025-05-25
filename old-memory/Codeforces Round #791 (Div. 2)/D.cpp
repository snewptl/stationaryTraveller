#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
vector<int>e[maxn],g[maxn];
ll a[maxn];
int n,m,k,in[maxn],dep[maxn];
ll ans=2e18;
void init(){
	for(int i=1;i<=n;i++)in[i]=dep[i]=0;
	for(int i=1;i<=n;i++)g[i].clear();
}
bool check(ll x){
	init();
	int sz=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x)continue;
		for(auto v:e[i]){
			if(a[v]>x)continue;
			g[i].push_back(v);
			in[v]++;
		}
	}
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(a[i]>x)continue;
		if(in[i]==0)q.push(i);
	}

	while(!q.empty()){
		int u=q.front();q.pop();
		if(dep[u]>=k-1)return true;
		for(auto v:g[u]){
			in[v]--;
			if(!in[v]){
				dep[v]=dep[u]+1;
				q.push(v);
			}
		}
	}

	for(int i=1;i<=n;i++){
		if(a[i]>x)continue;
		if(in[i])return true;
	}
	return false;
	
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
	}
	ll l=1,r=1e18;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid))r=mid-1,ans=min(mid,ans);
		else l=mid+1;
	}
	if(ans==2e18)puts("-1");
	else printf("%lld\n",ans);

	return 0;
}
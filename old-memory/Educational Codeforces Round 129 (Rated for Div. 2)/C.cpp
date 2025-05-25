#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
struct node{
	int a,b,idx;
}vec[maxn];
bool cmp(node x,node y){
	return x.a==y.a?x.b<y.b:x.a<y.a;
}
int n,rk[maxn],mp[maxn];
vector<pii>ans;
void solve(){
	ans.clear();
	for(int i=1;i<n;i++){
		if(vec[i].b>vec[i+1].b){
			puts("-1");
			return;
		}
	}	
	for(int i=1;i<=n;i++){
		int idx=vec[i].idx;
		if(idx!=i){
			ans.push_back({i,idx});
			vec[mp[i]].idx=idx;
			mp[idx]=mp[i];
		}
	}
	printf("%d\n",ans.size());
	for(auto it:ans)printf("%d %d\n",it.first,it.second);
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			vec[i]={0,0,i};
		}
		for(int i=1;i<=n;i++)scanf("%d",&vec[i].a);
		for(int i=1;i<=n;i++)scanf("%d",&vec[i].b);
		sort(vec+1,vec+n+1,cmp);
		for(int i=1;i<=n;i++)mp[vec[i].idx]=i;
		solve();
	}


	return 0;
}
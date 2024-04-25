#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int mx=0,n,cnt=0;
int ans,res;
vector<int>e[maxn],vec;
void init(){
	for(int i=1;i<=n;i++)e[i].clear();
	vec.clear();
	mx=0,cnt=0;
}
void dfs(int u){
	if(e[u].size())cnt++;
	int x=e[u].size();
	if(x)vec.push_back(x);
	mx=max(mx,x);
	for(auto v:e[u]){
		dfs(v);
	}
}
bool check(int x){
	int tot=0;
	for(int i=0;i<vec.size();i++){
		tot+=max(0,vec[i]-(x+cnt-i));
	}
	if(x>=tot)return true;
	else return false;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=2;i<=n;i++){
			int x;scanf("%d",&x);
			e[x].push_back(i);
		}
		dfs(1);
		cnt++;
		ans=cnt,res=1e9;
		sort(vec.begin(),vec.end());
		reverse(vec.begin(),vec.end());
		int l=0,r=1e9;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid))r=mid-1,res=min(mid,res);
			else l=mid+1;
		}
		ans+=res;
		printf("%d\n",ans);

	}


	return 0;
}
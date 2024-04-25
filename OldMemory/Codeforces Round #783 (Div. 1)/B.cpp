#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=5e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,ans;
ll a[maxn],pre[maxn];
set<pair<ll,int>>vec;
int dp[maxn];
void init(){
	ans=-1e9;
	vec.clear();
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			pre[i]=pre[i-1]+a[i];
		}
		vec.insert({0,0});
		dp[0]=0;
		for(int i=1;i<=n;i++){	
			auto it=vec.upper_bound({pre[i],1e9});
			if(a[i]>0)dp[i]=dp[i-1]+1;
			else if(a[i]<0)dp[i]=dp[i-1]-1;
			else dp[i]=dp[i-1];
			if(it==vec.begin());
			else {
				--it;
				auto p=*it;
				if(p.first==pre[i]){
					dp[i]=max(dp[p.second],dp[i]);
					if(it!=vec.begin()){
						--it;
						p=*it;
						dp[i]=max(dp[i],dp[p.second]+i-p.second);
					}
				}
				else {
					dp[i]=max(dp[p.second]+i-p.second,dp[i]);	
				}	
			}4
			it=vec.upper_bound({pre[i],1e9});
			if(it!=vec.begin()){
				--it;
				auto p=*it;
				if(dp[p.second]-p.second>=dp[i]-i)
					continue;
			}
			it=vec.lower_bound({pre[i],0});
			while(it!=vec.end()){
				auto p=*it;
				if(dp[p.second]-p.second<=dp[i]-i)vec.erase(p);
				else break;
				if(vec.empty())break;
				it=vec.lower_bound({pre[i],0});
			}
			vec.insert({pre[i],i});
		}
		printf("%d\n",dp[n]);
	}


	return 0;
}
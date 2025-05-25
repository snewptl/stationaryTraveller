#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=5e6+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,ans,a[maxn];
int cnt[maxn],dp[maxn],vis[maxn];
void init(){
	for(int i=1;i<=m;i++)vis[i]=dp[i]=cnt[i]=0;
	ans=m;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			vis[a[i]]=1;
			cnt[a[i]]=1;
		}
		for(int i=1;i<=m;i++)dp[i]=i;
		int mx=m,mn=0;
		while(!cnt[mn])mn++;
		while(!cnt[mx])mx--;
		ans=mx-mn;
		for(int i=m;i>=1;i--){
			if(1ll*i*i>m)continue;
			for(int j=i*i;j<=m;j+=i){
				if(vis[j])cnt[dp[j]]--;
				dp[j]=min(dp[j],dp[j/i]);
				if(vis[j])cnt[dp[j]]++;
				while(mx&&!cnt[mx])mx--;
				if(i<=mn)ans=min(ans,mx-i);
			}
		}
		printf("%d\n",ans);
	}


	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+10;
const ll mod=998244353;
const double eps=1e-10;
int n,a,b;
int x[maxn];
ll suf[maxn],pre[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&a,&b);
		for(int i=1;i<=n;i++)scanf("%d",&x[i]);
		suf[n]=0;
		for(int i=n-1;i>=0;i--){
			suf[i]=suf[i+1]+1ll*(x[i+1]-x[i])*(n-i)*b;
		}
		pre[0]=0;
		for(int i=1;i<=n;i++){
			pre[i]=1ll*(x[i]-x[0])*(a+b);
		}
		ll ans=4e18;
		for(int i=0;i<=n;i++){
			ans=min(pre[i]+suf[i],ans);
			// printf("#%d %lld\n",i,pre[i]+suf[i]);
		}
		printf("%lld\n",ans);
	}


	return 0;
}
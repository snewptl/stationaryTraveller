#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
ll ans=2e18;
ll pre[2][maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		ans=2e18;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		if(n%2){
			ll res=0;
			for(int i=2;i<n;i+=2){
				res+=max(0,max(a[i+1],a[i-1])+1-a[i]);
			}
			ans=res;
		}
		else {
			ll res=0;
			for(int i=2;i<n;i+=2){
				res+=max(0,max(a[i+1],a[i-1])+1-a[i]);
				pre[0][i]=res;
			}
			ans=min(res,ans);
			
			res=0;
			for(int i=3;i<n;i+=2){
				res+=max(0,max(a[i+1],a[i-1])+1-a[i]);
				pre[1][i]=res;
			}
			ans=min(res,ans);			

			for(int i=2;i<n;i+=2){
				ans=min(ans,pre[0][i]+pre[1][n-1]-pre[1][i+1]);
			}
		}
		printf("%lld\n",ans);
	}


	return 0;
}
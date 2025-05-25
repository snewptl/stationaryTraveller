#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
ll ed[2][maxn],a[2][maxn],dp[maxn];
ll ans;
int n;
int main(){
	int T=1;scanf("%d",&T);
	for(int cs=1;cs<=T;cs++){
		ans=1e18;
		scanf("%d",&n);
		for(int i=0;i<2;i++){
			for(int j=1;j<=n;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		for(int i=0;i<=n+1;i++){
			dp[i]=1e18;
			ed[0][i]=ed[1][i]=0;
		}
		for(int i=n;i>=1;i--){
			ed[0][i]=max(a[0][i],ed[0][i+1]-1);
			ed[0][i]=max(ed[0][i],a[1][i]-(n-i)*2-1);
			if(ed[0][i]<0)ed[0][i]=0;
			ed[1][i]=max(a[1][i],ed[1][i+1]-1);
			ed[1][i]=max(ed[1][i],a[0][i]-(n-i)*2-1);
			if(ed[1][i]<0)ed[1][i]=0;
		}
		dp[1]=a[1][1]+1;
		ans=max(ed[0][2]+(n-1)*2,a[1][1])+1;
		ans=min(ans,max(dp[1],ed[1][2])+(n-1)*2);
		// printf("%d\n",ed[1][2]);
		for(int i=2;i<=n;i++){
			ll temp0,temp1;
			temp0=max(dp[i-1],a[0][i])+1;
			temp1=max(dp[i-1],a[1][i])+1;
			if(i%2==0){
				dp[i]=max(temp1,a[0][i])+1;
				ans=min(ans,max(dp[i],ed[0][i+1])+(n-i)*2);
			}
			else {
				dp[i]=max(temp0,a[1][i])+1;
				ans=min(ans,max(dp[i],ed[1][i+1])+(n-i)*2);
			}	
			// printf("$$%d %d %d\n",i,temp0,temp1);
		}
		// if(cs==149){
		// 	printf("%d ",n);
		// 	for(int i=1;i<=n;i++)printf("%d ",a[0][i]);
		// 	for(int i=1;i<=n;i++)printf("%d ",a[1][i]);
		// }
		printf("%lld\n",ans);
	}


	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=5e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int ans;
int dp1[maxn],dp2[maxn][2],dp3[maxn];
void solve(){
	memset(dp1,0x3f,sizeof(dp1));
	memset(dp3,0x3f,sizeof(dp3));

	dp1[0]=-1;
	a[0]=0;
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]){
			dp1[i]=min(dp1[i-1],dp1[i]);
		}
		if(a[i]>dp1[i-1]){
			dp1[i]=min(dp1[i],a[i-1]);
		}
	}

	a[n+1]=0;
	dp3[n+1]=-1;
	for(int i=n;i>=1;i--){
		if(a[i]>a[i+1]){
			dp3[i]=min(dp3[i+1],dp3[i]);
		}
		if(a[i]>dp3[i+1]){
			dp3[i]=min(a[i+1],dp3[i]);
		}
	}

	for(int i=1;i<=n;i++)
		dp2[i][0]=1e9,dp2[i][1]=-1e9;
	int pos=0;
	for(int i=1;i<=n;i++)
		if(a[i]>a[pos])pos=i;
	dp2[pos][0]=dp1[pos];
	
	for(int i=pos+1;i<=n;i++){
		if(a[i]>a[i-1]){
			dp2[i][1]=max(dp2[i][1],dp2[i-1][1]);
		}
		if(a[i]<a[i-1]){
			dp2[i][0]=min(dp2[i][0],dp2[i-1][0]);
		}
		if(a[i]>dp2[i-1][0]){
			dp2[i][1]=max(dp2[i][1],a[i-1]);
		}
		if(a[i]<dp2[i-1][1]){
			dp2[i][0]=min(dp2[i][0],a[i-1]);
		}
		if(dp2[i][1]>dp3[i])ans++;
	}

	
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		solve();
		reverse(a+1,a+n+1);
		solve();
		printf("%d\n",ans);
	}


	return 0;
}
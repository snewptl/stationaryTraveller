#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+15;
const ll mod=1e9+7;
int n,m;
ll dp[10][maxn];
ll ans[maxn];
void init(){
	dp[0][0]=1;
	for(int i=1;i<=2e5+10;i++){
		for(int d=0;d<9;d++){
			dp[d+1][i]=dp[d][i-1];
		}
		dp[1][i]+=dp[9][i-1];
		dp[0][i]+=dp[9][i-1];
		for(int d=0;d<=9;d++)dp[d][i]%=mod;
	}
	for(int i=0;i<=2e5+10;i++){
		for(int d=0;d<=9;d++){
			ans[i]+=dp[d][i];
			ans[i]%=mod;
		}
	}
}
ll tot[10];
int main(){
	int T;scanf("%d",&T);init();
	while(T--){
		memset(tot,0,sizeof(tot));
		scanf("%d%d",&n,&m);
		while(n){
			tot[n%10]++;
			n/=10;
		}
		ll sum=0;
		for(int d=0;d<=9;d++){
			sum+=ans[m+d]*tot[d];
			sum%=mod;
		}
		printf("%lld\n",sum);
	}

	return 0;
}
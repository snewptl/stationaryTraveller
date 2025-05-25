#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+5;
int k,q;
double dp[maxn][8005];
int main(){
	dp[1][1]=1.0;
	scanf("%d%d",&k,&q);
	for(int i=2;i<=8000;i++){
		for(int j=min(i,k);j>=1;j--){
			dp[j][i]=dp[j][i-1]*j/k+dp[j-1][i-1]*(k-j+1)/k;
		}
	}
	while(q--){
		int d;
		scanf("%d",&d);
		double temp=1.0*d/2000;
		int pos=lower_bound(dp[k],dp[k]+8000,temp)-dp[k];
		printf("%d\n",pos);
	}

	return 0;
}
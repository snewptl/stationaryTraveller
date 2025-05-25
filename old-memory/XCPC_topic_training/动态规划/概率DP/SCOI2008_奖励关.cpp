#include<bits/stdc++.h>
using namespace std;
int K,n,v[16],state[16];
double dp[105][1<<15];
inline double Max(register double a,register double b){
	return a>b?a:b;
}
int main(){
	scanf("%d%d",&K,&n);
	int tmp;
	for(int i=1;i<=n;++i){
		scanf("%d",&v[i]);
		while(~scanf("%d",&tmp)){
			if(!tmp)break;
			state[i]|=(1<<(tmp-1));
		}
	}
	for(int i=K;i>=1;--i){
		for(int j=0;j<(1<<n);++j){
			for(int k=1;k<=n;++k){
				if((j&state[k])==state[k])dp[i][j]+=Max(dp[i+1][j],dp[i+1][j|(1<<(k-1))]+v[k]);
				else dp[i][j]+=dp[i+1][j];
			}
			dp[i][j]/=n;
		}
	}
	printf("%.6lf",dp[1][0]);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+5;
int w,b;
double dp[maxn][maxn];
int main(){
	scanf("%d%d",&w,&b);
	for(int i=1;i<=w;i++){
		for(int j=0;j<=b;j++){
			dp[i][j]=1.0*i/(i+j);
			if(j){
				double temp=1.0*j*(j-1)/((i+j)*(i+j-1));
				if(j>=2)dp[i][j]+=temp*i/(i+j-2)*dp[i-1][j-2];
				if(j>=3)dp[i][j]+=temp*(j-2)/(i+j-2)*dp[i][j-3];
			}
		}
	}
	printf("%.9lf",dp[w][b]);

	return 0;
}
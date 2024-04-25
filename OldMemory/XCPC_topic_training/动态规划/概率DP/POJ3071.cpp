#include<cstdio>
using namespace std;
typedef double db;
db mx=0.0;
db dp[10][1050],a[1050][1050];
int n;
int main(){
	int T=0;
	while(scanf("%d",&n)&&n!=-1){
		int maxlen=(1<<n);
		for(int i=0;i<=n;i++){
			for(int j=0;j<maxlen;j++)dp[i][j]=0.0;
		}
		for(int i=0;i<maxlen;i++){
			for(int j=0;j<maxlen;j++){
				scanf("%lf",&a[i][j]);
			}
		}
		for(int i=0;i<maxlen;i++)dp[0][i]=1.0;
		for(int i=1;i<=n;i++){//round
			int len=(1<<i);
			for(int j=0;j<maxlen;j+=len){//start
				for(int k=j;k<=j+len-1;k++){//win
					for(int t=j;t<=j+len-1;t++){//rival
						if(t/(len/2)==k/(len/2))continue;
						dp[i][k]+=dp[i-1][k]*dp[i-1][t]*a[k][t];
					}
				}
			}
		}
		int pos=0;mx=0.0;
		for(int i=0;i<maxlen;i++){
			if(mx<dp[n][i]){
				mx=dp[n][i];
				pos=i+1;
			}
			
		}
		if(T)printf("\n%d",pos);
		else printf("%d",pos);
		T++;
	}


	return 0;
}
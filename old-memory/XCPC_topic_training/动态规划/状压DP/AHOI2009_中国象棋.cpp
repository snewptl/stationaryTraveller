#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const ll mod=9999973;
ll dp[2][101][101];
ll c[101][101];
void init(){
	for(int i=0;i<=100;i++)c[i][i]=1,c[i][0]=1;
	for(int i=2;i<=100;i++){
		for(int j=1;j<i;j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			c[i][j]%=mod;
		}
	}
}
ll ans;
int main(){
	init();
	scanf("%d%d",&n,&m);
	dp[0][0][0]=1,dp[0][1][0]=c[m][1],dp[0][2][0]=c[m][2];
	for(int i=2;i<=n;i++){
		for(int x=0;x<=m;x++){
			for(int y=0;y<=m;y++){
				if(x+y>m)break;
				dp[1][x][y]=dp[0][x][y];
			}
		}		
		for(int x=0;x<=m;x++){
			for(int y=0;y<=m;y++){
				if(x+y>m)break;
				if(x){
					dp[0][x-1][y+1]+=dp[1][x][y]*c[x][1],dp[0][x-1][y+1]%=mod;
					dp[0][x][y+1]+=dp[1][x][y]*c[x][1]*c[m-x-y][1],dp[0][x][y+1]%=mod;
				}
				if(x>1){
					dp[0][x-2][y+2]+=dp[1][x][y]*c[x][2],dp[0][x-2][y+2]%=mod;
				}				
				dp[0][x+1][y]+=dp[1][x][y]*c[m-x-y][1],dp[0][x+1][y]%=mod;
				dp[0][x+2][y]+=dp[1][x][y]*c[m-x-y][2],dp[0][x+2][y]%=mod;

			}
		}
	}
	for(int x=0;x<=m;x++){
		for(int y=0;y<=m;y++){
			if(x+y>m)break;
			ans+=dp[0][x][y],ans%=mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
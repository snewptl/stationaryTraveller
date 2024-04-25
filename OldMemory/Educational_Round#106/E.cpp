#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const ll mod=998244353;
char x[maxn],y[maxn];
ll dp[maxn][maxn][2];
int sx[maxn],sy[maxn];
int lx,ly;
ll ans;
int main(){
	scanf("%s%s",x,y);
	int lx=strlen(x),ly=strlen(y);
	// for(int i=0;i<ly;i++)sy[y[i]-'a'][i]++;
	for(int i=1;i<=ly;i++){
		dp[0][i][0]=i;
		if(y[i]==y[i-1])break;
	}	
	for(int k=1;k<=lx;k++){
		for(int i=k;i<=lx;i++){
			dp[i][0][1]=i-k+1;
			if(x[i-1]==x[i])break;
		}
		for(int i=k;i<=lx;i++){
			for(int j=1;j<=ly;j++){
				if(x[i-1]!=y[j-1]){
					dp[i][j][1]+=dp[i-1][j][0];
					dp[i][j][0]+=dp[i][j-1][1];
					if(i>=2&&x[i-1]!=x[i-2])
						dp[i][j][1]+=dp[i-1][j][1];
					if(j>=2&&y[j-1]!=y[j-2])
						dp[i][j][0]+=dp[i][j-1][0];
				}
				else {
					if(i>=2&&x[i-1]!=x[i-2])
						dp[i][j][1]+=dp[i-1][j][1];
					if(j>=2&&y[j-1]!=y[j-2])
						dp[i][j][0]=dp[i][j-1][0];
				}
				dp[i][j][0]%=mod,dp[i][j][1]%=mod;
				ans+=dp[i][j][0]+dp[i][j][1],ans%=mod;
			}
		}
		for(int i=k;i<=lx;i++){
			for(int j=0;j<=ly;j++)
				dp[i][j][0]=dp[i][j][1]=0;
		}
	}
	printf("%lld\n",ans);


    return 0;
}
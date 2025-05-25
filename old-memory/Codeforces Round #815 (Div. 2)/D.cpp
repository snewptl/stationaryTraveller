#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=3e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[maxn];
int dp[maxn],mx[maxn];
int xr[205][maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<n;i++){
            for(int j=0;j<=200;j++)
            xr[j][i]=j^i;
        }
        dp[0]=1;
        mx[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=1;j<=400;j++){
                if(i-j<0)break;
                if(xr[a[i-j]][i]<xr[a[i]][i-j])dp[i]=max(dp[i-j]+1,dp[i]);
            }
            mx[i]=max(mx[i-1],dp[i]);
        }
        printf("%d\n",mx[n-1]);
	}


	return 0;
}
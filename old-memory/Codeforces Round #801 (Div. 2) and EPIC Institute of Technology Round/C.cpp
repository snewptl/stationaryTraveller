#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e3+5;
const ll mod=998244353;
const double eps=1e-10;
vector<int> dp[maxn][maxn];
int n,m;
int a[maxn][maxn];
bool solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i+j-1==(n+m)/2){
				for(auto x:dp[i][j]){
					auto it=lower_bound(dp[i+1][j].begin(),dp[i+1][j].end(),-x);
					if(it!=dp[i+1][j].end()&&(*it==-x))return true;
					it=lower_bound(dp[i][j+1].begin(),dp[i][j+1].end(),-x);
					if(it!=dp[i][j+1].end()&&(*it==-x))return true;
				}
			}
		}
	}
	return false;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
		}
		if((n+m)%2==0)puts("NO");
		else {

			dp[1][1].push_back(a[1][1]);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(i==1&&j==1)continue;
					if(i+j-1>(n+m)/2)break;
					int pos0=0,pos1=0;
					while(pos0<dp[i-1][j].size()&&pos1<dp[i][j-1].size()){
						if(dp[i-1][j][pos0]<=dp[i][j-1][pos1]){
							dp[i][j].push_back(dp[i-1][j][pos0]+a[i][j]);
							if(dp[i-1][j][pos0]==dp[i][j-1][pos1])pos1++;
							pos0++;
						}
						else {
							dp[i][j].push_back(dp[i][j-1][pos1]+a[i][j]);
							pos1++;
						}
					}
					while(pos0<dp[i-1][j].size())dp[i][j].push_back(dp[i-1][j][pos0]+a[i][j]),pos0++;
					while(pos1<dp[i][j-1].size())dp[i][j].push_back(dp[i][j-1][pos1]+a[i][j]),pos1++;
					dp[i-1][j].clear();
				}
			}			
			dp[n][m].push_back(a[n][m]);
			for(int i=n;i>=1;i--){
				for(int j=m;j>=1;j--){
					if(i==n&&j==m)continue;
					if((n-i+1)+(m-j+1)-1>(n+m)/2)break;
					int pos0=0,pos1=0;
					while(pos0<dp[i+1][j].size()&&pos1<dp[i][j+1].size()){
						if(dp[i+1][j][pos0]<=dp[i][j+1][pos1]){
							dp[i][j].push_back(dp[i+1][j][pos0]+a[i][j]);
							if(dp[i+1][j][pos0]==dp[i][j+1][pos1])pos1++;
							pos0++;
						}
						else {
							dp[i][j].push_back(dp[i][j+1][pos1]+a[i][j]);
							pos1++;
						}
					}
					while(pos0<dp[i+1][j].size())dp[i][j].push_back(dp[i+1][j][pos0]+a[i][j]),pos0++;
					while(pos1<dp[i][j+1].size())dp[i][j].push_back(dp[i][j+1][pos1]+a[i][j]),pos1++;
					dp[i+1][j].clear();
				}
			}
			if(solve())puts("YES");
			else puts("NO");
		}
		for(int i=1;i<=n+1;i++){
			for(int j=1;j<=m+1;j++)dp[i][j].clear();
		}

	}


	return 0;
}
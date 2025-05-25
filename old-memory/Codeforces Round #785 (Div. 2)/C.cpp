#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=4e4+5;
const ll mod=1e9+7;
const double eps=1e-10;
int n;
int dp[maxn][500];
int mp[500];
int ans[maxn];
bool  check(int x){
	vector<int>vec;
	while(x){
		vec.push_back(x%10);
		x/=10;
	}
	for(int i=0;i<vec.size()/2;i++){
		if(vec[i]!=vec[vec.size()-i-1])return false;
	}
	return true;
}
void init(){
	n=4e4;
	int tot=0;
	for(int i=1;i<=n;i++){
		if(check(i)){
			mp[++tot]=i;
		}
	}
	for(int i=1;i<=tot;i++)dp[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=tot;j++){
			if(i>=mp[j])dp[i][j]=dp[i-mp[j]][j];
			dp[i][j]+=dp[i][j-1],dp[i][j]%=mod;
			ans[i]=dp[i][j];
			
		}
		// printf("%d %d\n",i,n);
		
	}
}
int main(){
	int T=1;scanf("%d",&T);
	init();
	while(T--){
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}


	return 0;
}
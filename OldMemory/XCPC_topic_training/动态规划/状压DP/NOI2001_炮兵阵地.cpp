#include<bits/stdc++.h>
using namespace std;
int n,m;
int mp[105][105];
char s[105];
int dp[3][1050][1050];
int g[105][1050],tot[105],ans[105][1050];
int mx;
void dfs(int now,int dep,int x,int k){
	if(dep>=m)return;
	if(mp[now][dep]){
		int temp=0;
		if(dep>=1)temp+=x&(1<<(dep-1));
		if(dep>=2)temp+=x&(1<<(dep-2));
		if(!temp){
			tot[now]++;
			ans[now][tot[now]]=k+1;
			g[now][tot[now]]=x+(1<<dep);
			dfs(now,dep+1,x+(1<<dep),k+1);
		}
	}
	dfs(now,dep+1,x,k);
}
int main(){

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		for(int j=0;j<m;j++){
			if(s[j]=='P')mp[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		tot[i]++;
		dfs(i,0,0,0);
	}
	for(int i=1;i<=tot[1];i++){
		for(int j=1;j<=tot[2];j++){
			if((g[1][i]&g[2][j])==0){
				dp[0][i][j]=ans[1][i]+ans[2][j];
				mx=max(dp[0][i][j],mx);
			}
		}
	}
	for(int i=3;i<=n;i++){
		for(int fir=1;fir<=tot[i-2];fir++){
			for(int sec=1;sec<=tot[i-1];sec++){
				if((g[i-2][fir]&g[i-1][sec])!=0)continue;
				for(int thi=1;thi<=tot[i];thi++){
					if((g[i-2][fir]&g[i][thi])!=0)continue;
					if((g[i-1][sec]&g[i][thi])!=0)continue;
					dp[1][sec][thi]=max(dp[0][fir][sec]+ans[i][thi],dp[1][sec][thi]);
					mx=max(dp[1][sec][thi],mx);
				}
				
			}
		}
		for(int sec=1;sec<=tot[i-1];sec++){
			for(int thi=1;thi<=tot[i];thi++){
				dp[0][sec][thi]=dp[1][sec][thi];
				dp[1][sec][thi]=0;
			}
		}
	}
	printf("%d\n",mx);
	return 0;
}
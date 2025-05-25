#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e2+5;
const ll mod=1e9+7;
int a[maxn],len;
char s[maxn];
ll dp[maxn][15][4];
ll dfs(int dep,int pre,int opt,int lim){
	if(dep==len+1)return pre==-1?0:1;
	if(!lim&&pre!=-1&&dp[dep][pre][opt]!=-1)return dp[dep][pre][opt];
	int ret=lim?a[dep]:9;
	ll sum=0;
	for(int i=0;i<=ret;i++){
		if((opt==1||opt==3)&&i<pre)continue;
		if(pre==-1){
			if(i==0)sum+=dfs(dep+1,-1,opt,lim&(i==ret));
			else sum+=dfs(dep+1,i,opt,lim&(i==ret));
			sum%=mod;
		}
		else {
			if(i>pre){
				if(opt==2)sum+=dfs(dep+1,i,3,lim&(i==ret));
				else sum+=dfs(dep+1,i,opt?opt:1,lim&(i==ret));
			}
			else if(i<pre)sum+=dfs(dep+1,i,2,lim&(i==ret));
			else sum+=dfs(dep+1,i,opt,lim&(i==ret));
			sum%=mod;
		}
	}
	if(!lim&&pre!=-1)dp[dep][pre][opt]=sum;
	return sum;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		memset(dp,-1,sizeof(dp));
		scanf("%s",s);
		len=strlen(s);
		for(int i=0;i<len;i++){
			a[i+1]=s[i]-'0';
		}
		printf("%lld\n",dfs(1,-1,0,1));
	}

	return 0;
}
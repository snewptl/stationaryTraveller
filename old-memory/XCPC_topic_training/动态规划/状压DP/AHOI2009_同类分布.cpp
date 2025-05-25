//洛谷标程
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,dp[20][200][200];
int len,a[20],mod;
ll dfs(int pos,int sum,ll st,int limit)
{
	if(pos>len&&sum==0) return 0;
	if(pos>len) return st==0&&sum==mod?1:0;
	if(!limit&&dp[pos][sum][st]!=-1) return dp[pos][sum][st];
	ll ret=0;
	int res=limit?a[len-pos+1]:9;
	for(int i=0;i<=res;i++)
		ret+=dfs(pos+1,sum+i,(10ll*st+i)%mod,i==res&&limit);
	return limit?ret:dp[pos][sum][st]=ret;
}
ll part(ll x)
{
	len=0;
	while(x) a[++len]=x%10,x/=10;
	ll ret=0;
	for(mod=1;mod<=9*len;mod++)//枚举模数（就是各位数之和）
	{
		memset(dp,-1,sizeof dp);
	    ret+=dfs(1,0,0,1);
	}
	return ret;
}
int main()
{
    scanf("%lld%lld",&l,&r);
    printf("%lld\n",part(r)-part(l-1));
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2005;
const ll mod=1e9+7;
char s1[maxn],s2[maxn];
int cnt,dig[maxn];
int m,d;
ll dp[maxn][maxn][2];
ll dfs(int dep,int pre,int lim,int sum,int st){
	if(!dep){
		if(pre==-1)return 0;
		else if(!sum)return 1;
		else return 0;
	}
	int k=(st-dep+1)%2;
	if(!lim&&pre!=-1&&dp[dep][sum][k]!=-1)return dp[dep][sum][k];
	int ret=lim?dig[dep]:9;
	ll ans=0;
	for(int i=0;i<=ret;i++){
		if(i==d&&(pre==-1||k))continue;
		if(i!=d&&pre!=-1&&!k)continue;
		if(pre==-1&&i==0)ans+=dfs(dep-1,-1,0,0,-1);
		else ans+=dfs(dep-1,i,lim&(i==ret),(sum*10+i)%m,pre==-1?dep:st);
		ans%=mod;
	}
	if(pre!=-1&&!lim)dp[dep][sum][k]=ans;
	return ans;
}
ll cal(char *s){
	cnt=strlen(s);
	for(int i=1,j=cnt;i<=cnt;i++,j--)dig[j]=s[i-1]-'0';
	return dfs(cnt,-1,1,0,-1);
}
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d%d%s%s",&m,&d,s1,s2);
	int len=strlen(s1),sum=0,flag=1;
	for(int i=0;i<len;i++){
		sum=sum*10+s1[i]-'0';
		sum%=m;
		if(i%2==0&&s1[i]-'0'==d)flag=0;
		if(i%2&&s1[i]-'0'!=d)flag=0;
	}
	if(sum)flag=0;
	printf("%lld\n",(cal(s2)-cal(s1)+flag+mod)%mod);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=30;
const ll mod=2520;
char s1[maxn],s2[maxn];
ll a,b;
int cnt,dig[maxn];
ll dp[20][2525][55];
int tot;
map<int,int>mp;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
ll dfs(int dep,int pre,int lim,int sum,int pai){
	if(!dep){
		if(pre==-1)return 0;
		else return sum%pai==0?1:0;
	}
	if(!lim&&pre!=-1&&dp[dep][sum][mp[pai]]!=-1)return dp[dep][sum][mp[pai]];
	int ret=lim?dig[dep]:9;
	ll ans=0;
	for(int i=0;i<=ret;i++){
		int temp=!i?pai:pai*i/gcd(pai,i);
		if(mp.find(temp)==mp.end())mp[temp]=++tot;
		if(pre==-1&&i==0)ans+=dfs(dep-1,pre,0,sum,pai);
		else ans+=dfs(dep-1,i,lim&(i==ret),(sum*10+i)%mod,temp);
	}
	if(pre!=-1&&!lim)dp[dep][sum][mp[pai]]=ans;
	return ans;
}
ll cal(ll m){
	cnt=0;
	while(m){
		dig[++cnt]=m%10;
		m/=10;
	}
	return dfs(cnt,-1,1,0,1);
}
int main(){
	int T;scanf("%d",&T);
	memset(dp,-1,sizeof(dp));tot=0;mp.clear();
	while(T--){
		cin>>a>>b;
		cout<<cal(b)-cal(a-1)<<endl;
	}
	return 0;
}
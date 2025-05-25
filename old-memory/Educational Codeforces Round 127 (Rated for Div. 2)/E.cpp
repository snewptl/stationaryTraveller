#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
char ch[300005];
long long dp[300005];
string dfs(int x) {
	if(x>=(1<<(n-1))) {
		dp[x]=1;
		return ch[x]+"";
	}
	string a=dfs(x<<1),b=dfs(x<<1|1);
	dp[x]=dp[x<<1]*dp[x<<1|1]%mod;
	if(a!=b)dp[x]=dp[x]*2%mod;
	if(a>b)swap(a,b);
	return ch[x]+a+b;
}
int main() {
	scanf("%d\n%s",&n,ch+1);
	dfs(1);
	printf("%lld",dp[1]);
	return 0;
}

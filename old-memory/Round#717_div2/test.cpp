#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
const ll mod=1e9+7;
int n;
ll fib[maxn];
ll dp[maxn];
int main(){
	fib[0]=1;fib[1]=1;
	for(int i=1;i<maxn;i++){
		fib[i]=fib[i-1]+fib[i-2],fib[i]%=mod;
	}
	int T;scanf("%d",&T);
	ll 
	while(T--){
		scanf("%d\n",&n);
		for(int i=n;i>=2;i--){
			for(int j=i;j<=n;j+=i){
				dp[i]+=fib[j-i];
				dp[i]%=mod;
			}
			for(int j=i*2;j<=n;j+=i){
				dp[i]-=dp[j];
				dp[i]=(dp[i]+mod)%mod;
			}
		}		
	}
	

	return 0;
}
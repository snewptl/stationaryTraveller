#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e6+10;
const ll mod=998244353;
ll dp[maxn];
ll sum[maxn];
int n;
int fac[maxn];
void get_fac(){
	for(int i=1;i<=n;i++)
		fac[i]=1;
    for(int i=2;i<=n;i++)
        if(fac[i]==1)
            for(int j=i,k=1;j<=n;j+=i,k++){
                int x=j,temp=0;
				while(x%i==0)temp++,x/=i;
				fac[j]*=temp+1;
            }
}
int main(){
    scanf("%d",&n);
	get_fac();
	for(int i=1;i<=n;i++){
		dp[i]=sum[i-1]+fac[i];
		sum[i]=dp[i]+sum[i-1];
		sum[i]%=mod;
		dp[i]%=mod;
		// printf("%d\n",dp[i]);
	}
	printf("%lld\n",(dp[n]+mod)%mod);

    return 0;
}
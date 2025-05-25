#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n;
ll k;
ll dp[maxn];
int ans[maxn];
void dfs(int st,ll k){
	ll temp=0;
	if(st==n+1)return;
	for(int i=st;i<=n;i++){
		temp+=dp[n-i];
		if(temp<k)continue;
		for(int j=i;j>=st;j--)ans[st+i-j]=j;
		dfs(i+1,k-temp+dp[n-i]);
		break;
	}
}
int main(){
    int T;scanf("%d",&T);
	ll sum=1;dp[0]=1;
	for(int i=1;i<maxn;i++){
		dp[i]=sum;
		if(sum<=1e18)sum+=dp[i];
	}
    while(T--){
        scanf("%d%lld",&n,&k);
		if(k>dp[n])printf("-1\n");
		else {
			for(int i=1;i<=n;i++){
				if(dp[i]<k)continue;	
				for(int j=1;j<=n-i;j++)ans[j]=j;
				dfs(n-i+1,k);
				break;
			}
			for(int i=1;i<=n;i++)printf("%d ",ans[i]);
			printf("\n");			
		}

	}


    return 0;
}
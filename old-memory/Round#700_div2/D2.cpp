#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,cnt,ans;
int a[maxn],b[maxn],dp[maxn],now[maxn],nxt[maxn];
int main(){
    scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i+1])b[++cnt]=a[i];
	for(int i=1;i<=n;i++)now[i]=-1;
	for(int i=1;i<=cnt;i++){
		nxt[i]=now[b[i]];
		now[b[i]]=i;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[1]=1;ans=0x3f3f3f3f;
	for(int i=2;i<=cnt;i++){
		dp[i]=min(dp[i-1]+1,dp[nxt[i]+1]+i-nxt[i]-2);
	}
	for(int i=1;i<=cnt;i++){
		ans=min(dp[i]+cnt-i,ans);
	}
	printf("%d",ans);
    return 0;
}
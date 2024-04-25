#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
const int mxlen=1000;
const int d=13;
char s[maxn];
int n;
int dp[maxn][mxlen+5],hsh[maxn],p[maxn],
	mx[mxlen+5],g[mxlen+5],f[maxn][mxlen+5];
void init(){
	p[0]=1;
	for(int i=1;i<=n;i++)p[i]=1ll*d*p[i-1]%mod;
	for(int i=1;i<=n;i++){
		hsh[i]=(hsh[i-1]+1ll*p[i-1]*(s[i]-'0'))%mod;
	}
}
void mul(int &x){
	if(x>=mod)x-=mod;
	else if(x<0)x+=mod;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	init();
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=mxlen;j++){
			mx[j]=mx[j-1],g[j]=g[j-1];
			if(i<=j||!f[i-j][j])continue;
			if(dp[i-j][j]>mx[j])mx[j]=dp[i-j][j],g[j]=0;
			if(dp[i-j][j]==mx[j])g[j]+=f[i-j][j],mul(g[j]);
		}
		if(i==n+1)break;
		for(int j=1;j<=min(mxlen,n-i+1);j++){
			if(i<n-mxlen*30&&j>mxlen/2)break;
			if(i==1){
				dp[i][j]=1,f[i][j]=1;
			}	
			else {
				if(g[j-1])
					dp[i][j]=mx[j-1]+1,f[i][j]=g[j-1];
				if(i>j&&f[i-j][j]){
					int l=1,r=j,res=0;
					while(l<=r){
						int mid=l+r>>1;
						if((hsh[i-j+mid-1]-hsh[i-j-1]+mod)%mod*p[j]%mod
							==(hsh[i+mid-1]-hsh[i-1]+mod)%mod)
							l=mid+1,res=max(res,mid);
						else r=mid-1;
					}
					if(res==j||s[i+res]>=s[i-j+res]){
						dp[i][j]=mx[j]+1,f[i][j]=g[j];				
					}
				}
			}
		}
	}
	printf("%d %d\n",mx[min(n,mxlen)],g[min(n,mxlen)]);
	return 0;
}
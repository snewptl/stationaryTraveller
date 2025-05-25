#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
const ll mod=998244353;
vector<int>a[maxn],b[maxn];
int n,m;
char s[maxn];
ll f[maxn],g[maxn];
ll sum[2],meth[2];
ll psum[2],pmeth[2];
ll ans,cnt;
ll mi[maxn];
void init(){
	meth[0]=1,pmeth[0]=1;
	// f[3]=1,psum[1]=1,sum[1]=1;
	for(int i=1;i<maxn;i++){
		int sgn=i&1;
		f[i]=psum[sgn]+psum[sgn^1]+
			meth[sgn^1]-pmeth[sgn^1]+meth[sgn]-pmeth[sgn]+mod*2,f[i]%=mod;
		psum[sgn]+=f[i],psum[sgn]%=mod;
		// sum[sgn]+=psum[sgn],sum[sgn]%=mod;
		g[i]=pmeth[sgn]+pmeth[sgn^1],g[i]%=mod;
		pmeth[sgn]+=g[i],pmeth[sgn]%=mod;
		meth[sgn]+=pmeth[sgn],meth[sgn]%=mod;
		// if(i<=10)printf("%d %d %d\n",i,f[i],g[i]);
	}	
	mi[0]=1;
	for(int i=1;i<maxn;i++)mi[i]=mi[i-1]*2,mi[i]%=mod;
}
int main(){
	init();
	scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
		scanf("%s",s);
		for(int j=0;j<m;j++){
			if(s[j]=='*'){
				a[i].push_back(0);
				b[j].push_back(0);
			}
			else {
				a[i].push_back(1);
				b[j].push_back(1);
				cnt++;
			}
		}
	}
	for(int i=0;i<n;i++)a[i].push_back(0);
	for(int i=0;i<m;i++)b[i].push_back(0);
	for(int i=0;i<n;i++){
		int st=-1;
		for(int j=0;j<=m;j++){
			if(!a[i][j]){
				ans+=f[j-st]*mi[cnt-(j-st-1)],ans%=mod;
				st=j;
			}
		}
	}
	for(int j=0;j<m;j++){
		int st=-1;
		for(int i=0;i<=n;i++){
			if(!b[j][i]){
				ans+=f[i-st]*mi[cnt-(i-st-1)],ans%mod;
				st=i;
			}
		}
	}
	printf("%lld\n",ans);
    return 0;
}
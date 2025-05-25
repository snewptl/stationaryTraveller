#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e7;
const int maxm=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxm];
int cnt[maxn+5];
ll val[maxn+5];
int pri[maxn+5];
int vis[maxn+5];
int tot;
int main(){
	int T=1;
	while(T--){
		scanf("%d",&n);
		for(int i=2;i<=n;i++){
			if(!vis[i])pri[++tot]=i;
			for(int j=1;j<=tot&&pri[j]*i<=maxn;j++){
				vis[pri[j]*i]=1;
				if(i%pri[j]==0)break;
			}
		}
		for(int i=1;i<=n;i++){


				
		}
		for(int i=maxn;i>=1;i--){
			for(int j=1;j<=tot&&pri[j]*i<=maxn;j++){
				
			}
		}
		ll ans=0;
		for(int i=5e6;i>=1;i--){
			if(!cnt[i])continue;
			val[i]=max(val[i],1ll*cnt[i]*i);
			for(int j=1;j*j<=i;j++){
				if(i%j==0){
					val[j]=max(1ll*(cnt[j]-cnt[i])*j+val[i],val[j]);
					if(i/j!=j){
						val[i/j]=max(1ll*(cnt[i/j]-cnt[i])*i/j+val[i],val[i/j]);
					}
				}
			}
			ans=max(ans,val[i]);
		}
		printf("%lld\n",ans);
	}


	return 0;
}
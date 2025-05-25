#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k;
int a[maxn];
ll ans,pre[maxn];
void init(){
	ans=0;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			pre[i]=pre[i-1]+a[i];
		}
		if(k<=n){
			for(int i=k;i<=n;i++){
				ans=max(ans,pre[i]-pre[i-k]);
			}
			ans+=1ll*(k-1)*k/2;
		}
		else {
			ans=pre[n]+1ll*k*n-1ll*(1+n)*n/2;
		}
		printf("%lld\n",ans);
		
	}


	return 0;
}
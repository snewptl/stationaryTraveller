#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,x,a[maxn];
ll pre[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
		int ed=n;
		ll k=0;
		ll ans=0;
		while(ed){
			ll temp=(x-pre[ed]-1ll*k*ed);
			if(temp>=0)ans+=1ll*(temp/ed+1)*ed,k+=temp/ed+1;
			ed--;
		}	
		printf("%lld\n",ans);
	}


	return 0;
}
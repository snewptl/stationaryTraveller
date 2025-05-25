#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod=1e9+7;
const int maxn=2e5+5;
int vis[35],a[maxn];
int cnt;
int n;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);cnt=0;
		for(int i=0;i<=30;i++)vis[i]=1;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			for(int j=0;j<=30;j++){
				if(((1<<j)&a[i])==0)vis[j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			int flag=1;
			for(int j=0;j<=30;j++){
				if(vis[j])continue;
				if((1<<j)&a[i])flag=0;
			}
			if(flag)cnt++;
		}
		ll ans=1LL*cnt*(cnt-1);
		ans%=mod;
		for(int i=1;i<=n-2;i++){
			ans*=i;ans%=mod;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
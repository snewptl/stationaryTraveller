#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=1e9+7;
const double eps=1e-10;
int n,k;
ll mi[105];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		ll ans=0;
		mi[0]=1;
		for(int i=1;i<=60;i++)mi[i]=mi[i-1]*n,mi[i]%=mod;
		for(int i=0;i<30;i++){
			if((1ll<<i)&k){
				ans+=mi[i],ans%=mod;
			}
		}
		printf("%lld\n",ans);
	}


	return 0;
}
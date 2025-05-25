#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int x,y,n,mx;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&mx,&x,&y);
		ll cur=0;
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(cur+x<=mx)cur+=x;
			else cur-=y;
			ans+=cur;
		}
		printf("%lld\n",ans);
	}


	return 0;
}
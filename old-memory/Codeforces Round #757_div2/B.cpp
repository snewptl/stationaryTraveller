#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
ll ans;
int c[maxn];
pii b[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]={a[i],i};
		}
		sort(b+1,b+n+1);
		int cur=1;
		c[0]=0;
		for(int i=n;i>=1;i--){
			ans+=1ll*b[i].first*abs(cur)*2;
			c[b[i].second]=cur;
			if(cur>0)cur=-cur;
			else cur=-cur,cur++;
		}
		printf("%lld\n",ans);
		for(int i=0;i<=n;i++)
			printf("%d ",c[i]);
		puts("");
	}


	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,q;
ll p[maxn];
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)scanf("%lld",&p[i]);
		sort(p+1,p+n+1);
		reverse(p+1,p+n+1);
		for(int i=1;i<=n;i++){
			p[i]+=p[i-1];
		}
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",p[x]-p[x-y]);
		}
	}


	return 0;
}
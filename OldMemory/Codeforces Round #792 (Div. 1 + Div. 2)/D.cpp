#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k,a[maxn],b[maxn];
ll sum;
void init(){
	sum=-1ll*k*(k-1)/2;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for(int i=1;i<=n;i++){
			b[i]=(n-i)-a[i];
		}
		sort(b+1,b+n+1);
		for(int i=1;i<=k;i++){
			sum+=b[i];
		}
		printf("%lld\n",sum);
	}


	return 0;
}
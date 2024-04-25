#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[30],b[30];
ll ans;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		for(int i=2;i<=n;i++){
			int res=min(abs(a[i]-a[i-1])+abs(b[i]-b[i-1]),abs(b[i]-a[i-1])+abs(a[i]-b[i-1]));
			ans+=res;
		}
		printf("%lld\n",ans);
	}


	return 0;
}
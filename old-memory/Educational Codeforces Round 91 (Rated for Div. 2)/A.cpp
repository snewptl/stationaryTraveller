#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int pre[maxn],nxt[maxn],a[maxn],b[maxn];
int n;
void solve(){
	for(int i=2;i<n;i++){
		if(pre[i-1]<a[i]&&nxt[i+1]<a[i]){
			printf("YES\n%d %d %d\n",b[pre[i-1]],i,b[nxt[i+1]]);
			return ;
		}
	}
	printf("NO\n");
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[a[i]]=i;
		}
		pre[0]=maxn,nxt[n+1]=maxn;
		for(int i=1;i<=n;i++)pre[i]=min(pre[i-1],a[i]);
		for(int i=n;i>=1;i--)nxt[i]=min(nxt[i+1],a[i]);
		solve();

	}


	return 0;
}
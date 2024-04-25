#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=1e9+7;
const double eps=1e-10;
int n,a[maxn],rk[maxn];
ll ans;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int l=1e9,r=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			rk[a[i]]=i;
			if(a[i]==0||a[i]==1){
				l=min(l,i);
				r=max(r,i);
			}
		}
		ans=1;
		for(int i=2;i<n;i++){
			if(rk[i]<=r&&rk[i]>=l)ans*=(r-l+1-i),ans%=mod;
			else {
				l=min(l,rk[i]);
				r=max(r,rk[i]);
			}
		}
		printf("%lld\n",ans);
	}


	return 0;
}
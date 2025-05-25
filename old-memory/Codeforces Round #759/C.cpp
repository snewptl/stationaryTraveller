#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
const int inf=1e9;
int n,k;
int a[maxn];
ll ans;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&k);
		int mx=-inf,mn=inf;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mn=min(mn,a[i]);
			mx=max(mx,a[i]);
		}
		sort(a+1,a+n+1);
		if(a[1]==a[n]){
			ans=1ll*(((n-1)/k+1)*2-1)*abs(a[1]);
		}
		else if(abs(mn)<abs(mx)){
			int r=n;
			for(int i=n;i>=n-k+1;i--){
				if(a[i]<0)break;
				r--;
			}
			ans+=abs(mx);
			for(;r>=1;r-=k){
				if(a[r]<0)break;
				ans+=abs(a[r])*2;
			}
			while(r<=0)r++;
			while(r<=n&&a[r]<0)r++;
			r--;
			for(int i=1;i<=r;i+=k){
				ans+=2*abs(a[i]);
			}
		}
		else {
			int l=1;
			for(int i=1;i<=k;i++){
				if(a[i]>0)break;
				l++;
				
			}
			ans+=abs(mn);
			for(;l<=n;l+=k){
				if(a[l]>0)break;
				ans+=abs(a[l])*2;
				
			}
			while(l>n)l--;
			while(l>=1&&a[l]>0)l--;
			l++;
			for(int i=n;i>=l;i-=k){
				ans+=abs(a[i])*2;
			}
		}
		printf("%lld\n",ans);

	}


	return 0;
}
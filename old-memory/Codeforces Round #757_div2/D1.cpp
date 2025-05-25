#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=5e6+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int cnt[maxn];
ll val[maxn];
vector<pii>vec[2];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int T=1;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			for(int j=1;j*j<=a[i];j++){
				if(a[i]%j==0){
					cnt[j]++;
					if(a[i]/j!=j)cnt[a[i]/j]++;
				}
			}
		}
		ll ans=0;
		for(int i=5e6;i>=1;i--){
			if(!cnt[i])continue;
			val[i]=max(val[i],1ll*cnt[i]*i);
			for(int j=1;j*j<=i;j++){
				if(i%j==0){
					val[j]=max(1ll*(cnt[j]-cnt[i])*j+val[i],val[j]);
					if(i/j!=j){
						val[i/j]=max(1ll*(cnt[i/j]-cnt[i])*i/j+val[i],val[i/j]);
					}
				}
			}
			ans=max(ans,val[i]);
		}
		printf("%lld\n",ans);
	}


	return 0;
}
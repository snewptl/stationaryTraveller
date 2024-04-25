#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int a[maxn],n;
ll b[maxn],ans;
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		ans=1e18;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			ll pre=0,res=0;
			for(int j=i+1;j<=n;j++){
				ll temp=pre/a[j]+1;
				res+=temp;
				pre=temp*a[j];
			}
			pre=0;
			for(int j=i-1;j>=1;j--){
				ll temp=pre/a[j]+1;
				res+=temp;
				pre=temp*a[j];
			}
			ans=min(res,ans);
		}
		printf("%lld\n",ans);
	}


	return 0;
}
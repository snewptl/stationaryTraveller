#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        ll ans=2e9;
        for(int i=2;i<n;i++){
            ans=min(ans,1ll*a[i+1]-a[i-1]);
        }
        printf("%lld\n",ans);
	}


	return 0;
}
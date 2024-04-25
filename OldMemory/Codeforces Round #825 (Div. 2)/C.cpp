#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn],pre[maxn];
ll ans;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        pre[1]=1;
        ans=pre[1];
        for(int i=2;i<=n;i++){
            pre[i]=min(pre[i-1]+1,a[i]);
            ans+=pre[i];
        }
        printf("%lld\n",ans);
	}


	return 0;
}
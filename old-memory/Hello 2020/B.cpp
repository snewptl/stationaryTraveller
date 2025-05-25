#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
vector<int>a[maxn];
int mn[maxn],mx[maxn],vis[maxn];
int sum[maxn*10],cnt;
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int sz;scanf("%d",&sz);
			for(int j=1;j<=sz;j++){
				int x;scanf("%d",&x);
				a[i].push_back(x);
			}
			mn[i]=a[i][0];
			mx[i]=a[i][0];
			for(int j=1;j<a[i].size();j++){
				if(a[i][j]>mn[i])vis[i]=1;
				else mn[i]=a[i][j];
				mx[i]=max(mx[i],a[i][j]);
			}
			if(!vis[i])sum[mx[i]]++;
			else cnt++;
		}
		int ed=1e6;
		for(int i=1;i<=ed;i++){
			sum[i]+=sum[i-1];
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(vis[i])ans+=n;
			else ans+=sum[ed]-sum[mn[i]]+cnt;
		}
		printf("%lld\n",ans);
	}


	return 0;
}
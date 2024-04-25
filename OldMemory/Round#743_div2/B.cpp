#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[maxn],b[maxn];
int res[maxn],mn[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		for(int i=1;i<=n;i++){
			res[b[i]]=i-1;
		}
		mn[n+1]=1e9;
		for(int i=n;i>=1;i--){
			mn[i]=min(mn[i+1],res[i*2]);
		}
		int ans=1e9;
		for(int i=1;i<=n;i++){
			ans=min(mn[a[i]/2+1]+i-1,ans);
		}
		printf("%d\n",ans);
	}


	return 0;
}
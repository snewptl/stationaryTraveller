#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
map<int,int>mp;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		mp.clear();
		int mx=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mp[a[i]]++;
			mx=max(mp[a[i]],mx);
		}
		int ans=0;
		while(mx<n){
			ans+=1;
			ans+=min(n-mx,mx);
			mx*=2;
		}
		printf("%d\n",ans);
	}


	return 0;
}
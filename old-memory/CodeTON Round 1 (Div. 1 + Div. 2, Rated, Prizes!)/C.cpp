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
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mp[a[i]]=1;
		}
		sort(a+1,a+n+1);
		int flag=1;
		for(int i=1;i<n;i++){
			if(mp[a[i]+1]&&mp[1])flag=0;
		}
		if(!flag)puts("NO");
		else puts("YES");
	}


	return 0;
}
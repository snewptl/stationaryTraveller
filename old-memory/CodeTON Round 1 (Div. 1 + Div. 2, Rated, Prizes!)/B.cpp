#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k;
map<int,int>mp;
int a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		mp.clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mp[a[i]]=1;
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			if(mp[a[i]+k])flag=1;
		}
		if(flag)puts("YES");
		else puts("NO");
		
	}


	return 0;
}
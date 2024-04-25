#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
int a[maxn],vis[maxn];
void init(){
	for(int i=1;i<=n;i++)vis[i]=0;
}
bool check(int x){
	ll cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]>=x)cnt+=vis[i]-x;
		else {
			cnt-=(x-vis[i])/2;
		}
	}
	if(cnt>0)return false;
	return true;
}
int main(){
	int T=1;scanf("%d",&T); 
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
			vis[a[i]]++;
		}
		sort(vis+1,vis+n+1);
		int l=1,r=m;
		while(l<r){
			int mid=l+r>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
		
	}


	return 0;
}
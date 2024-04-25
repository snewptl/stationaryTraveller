#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,cnt;
int a[maxn],b[maxn],vis[maxn];
int rka[maxn],rkb[maxn];
void init(){
	for(int i=1;i<=n;i++)vis[i]=0;
	cnt=0;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			rka[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
			rkb[b[i]]=i;
		}
		for(int i=1;i<=n;i++){
			if(vis[a[i]])continue;
			vis[a[i]]=1;
			int sz=1;
			int cur=b[i];
			while(!vis[cur]){
				vis[cur]=1;
				sz++;
				cur=b[rka[cur]];
			}
			if(sz%2)cnt++;
		}
		ll ans=0;
		for(int i=1;i<=(n-cnt)/2;i++){
			ans+=n-i+1-i;
		}
		printf("%lld\n",ans*2);
	}



	return 0;
}
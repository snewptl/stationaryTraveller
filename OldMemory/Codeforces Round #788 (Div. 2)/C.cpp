#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=1e9+7;
const double eps=1e-10;
int vis[maxn],n;
int a[maxn],b[maxn],d[maxn];
int rka[maxn],rkb[maxn];
int mi[maxn];
void init(){
	for(int i=1;i<=n;i++)vis[i]=0;
}
int main(){
	int T=1;scanf("%d",&T);
	mi[0]=1;
	for(int i=1;i<=1e5;i++)mi[i]=mi[i-1]*2,mi[i]%=mod;
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
			scanf("%d",&d[i]);
			if(d[i])vis[d[i]]=1;
			if(a[i]==b[i])vis[a[i]]=1;
		}
		for(int i=1;i<=n;i++){
			if(vis[a[i]]){
				int cur=b[i];
				while(!vis[cur]){
					vis[cur]=1;
					cur=b[rka[cur]];
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[a[i]])continue;
			cnt++;
			int cur=a[i];
			while(!vis[cur]){
				vis[cur]=1;
				cur=b[rka[cur]];
			}
		}
		printf("%lld\n",mi[cnt]);
	}


	return 0;
}
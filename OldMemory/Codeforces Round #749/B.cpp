#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
int vis[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)vis[i]=1;
		for(int i=1;i<=m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			vis[b]=0;
		}
		int pos=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				pos=i;break;
			}
		}
		for(int i=1;i<=n;i++){
			if(i==pos)continue;
			printf("%d %d\n",i,pos);
		}
	}


	return 0;
}
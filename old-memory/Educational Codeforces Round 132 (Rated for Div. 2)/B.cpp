#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
int a[maxn];
ll pre[maxn],nxt[maxn];
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=2;i<=n;i++){
			pre[i]=pre[i-1]+max(a[i-1]-a[i],0);
		}
		nxt[n]=0;
		for(int i=n-1;i>=1;i--){
			nxt[i]=nxt[i+1]+max(a[i+1]-a[i],0);
		}
		for(int i=1;i<=m;i++){
			int s,t;
			scanf("%d%d",&s,&t);
			if(s<=t)printf("%lld\n",pre[t]-pre[s]);
			else printf("%lld\n",nxt[t]-nxt[s]);
		}
	}


	return 0;
}
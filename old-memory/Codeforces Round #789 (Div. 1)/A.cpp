#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=5e3+5;
const ll mod=998244353;
const double eps=1e-10;
int inv[maxn][maxn];
int pre[maxn][maxn];
int n,p[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&p[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				pre[i][j]=pre[i][j-1];
				if(p[j]>p[i])pre[i][j]++;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				inv[i][j]=inv[i][j-1];
				inv[i][j]+=pre[j][j]-pre[j][i-1];
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(p[i]<p[j]){
					ans+=inv[i+1][n]-inv[i+1][j-1]-inv[j][n]-(pre[j][j]-pre[j][i]);
				}
			}
		}
		printf("%lld\n",ans);
	}


	return 0;
}
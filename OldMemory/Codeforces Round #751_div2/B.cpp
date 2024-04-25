#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e3+5;
const ll mod=998244353;
const double eps=1e-10;
int n,q;
int a[maxn];
int cur[maxn][maxn];
int cnt[maxn][maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++)cnt[i][j]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			cur[0][i]=a[i];
			cnt[0][a[i]]++;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int tot=cnt[i-1][cur[i-1][j]];
				cur[i][j]=tot;
				cnt[i][tot]++;				
			}
		}
		scanf("%d",&q);
		while(q--){
			int x,k;
			scanf("%d%d",&x,&k);
			if(k>=n)printf("%d\n",cur[n][x]);
			else printf("%d\n",cur[k][x]);
			
		}
	}


	return 0;
}
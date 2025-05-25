#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
vector<int>vec[maxn];
ll col[maxn],row[maxn],sum[maxn];
ll temp[maxn],pos[maxn],ans;
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			vec[i].push_back(0);
			for(int j=1;j<=m;j++){
				int x;
				scanf("%d",&x);
				vec[i].push_back(x);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int id=vec[i][j];
				if(pos[id]<i){
					col[id]+=1ll*(i-pos[id])*sum[id];
					pos[id]=i;
				}
				ans+=col[id];
				sum[id]++;
			}
		}
		memset(sum,0,sizeof(sum));
		memset(pos,0,sizeof(pos));
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				int id=vec[i][j];
				if(pos[id]<j){
					row[id]+=1ll*(j-pos[id])*sum[id];
					pos[id]=j;
				}
				ans+=row[id];
				sum[id]++;
			}
		}
		printf("%lld\n",ans);
	}


	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
pii ans;
vector<int>a[maxn],b[maxn];
void solve(){
	for(int i=1;i<=n;i++){
		vector<int>cur;
		for(int j=0;j<m;j++){
			if(a[i][j]!=b[i][j])cur.push_back(j);
		}
		if(cur.size()==2){
			ans={cur[0],cur[1]};
			break;
		}
	}
	for(int i=1;i<=n;i++)swap(a[i][ans.first],a[i][ans.second]);
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]!=b[i][j]){
				puts("-1");
				return;
			}
		}
	}
	printf("%d %d\n",ans.first+1,ans.second+1);
}
void init(){
	ans={0,0};
	for(int i=1;i<=n;i++){
		a[i].clear();
		b[i].clear();
	}
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=n;i++){
			int x;
			for(int j=1;j<=m;j++){
				scanf("%d",&x);
				a[i].push_back(x);
				b[i].push_back(x);
			}
			sort(a[i].begin(),a[i].end());
		}
		solve();
	}


	return 0;
}
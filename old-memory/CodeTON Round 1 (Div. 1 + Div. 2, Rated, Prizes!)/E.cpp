#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[maxn],p[maxn];
int fa[maxn][35];
int in[maxn];
int cnt,cur,mx;
int vis[maxn];
// set<int>dis;
queue<int>dis;
vector<int>vec[maxn];
int ans[maxn];
int idx[maxn];
int rk[maxn];
set<int>s;
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&p[i]);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			fa[i][0]=p[i];
			mx=max(mx,a[i]);
			if(a[i]<=n)rk[a[i]]=i;
			in[p[i]]++;
		}
		for(int i=1;i<=n;i++)if(!in[i])cnt++;
		for(int i=1;i<=30;i++){
			for(int j=1;j<=n;j++){
				fa[j][i]=fa[fa[j][i-1]][i-1];
			}
		}
		int t=0;
		if(cnt)t=(mx-n)/cnt;	
		for(int i=1;i<=n;i++){
			int u=i;
			for(int j=30;j>=0;j--){
				if(t&(1<<j))u=fa[u][j];
			}
			vec[u].push_back(i);
		}
		for(int i=1;i<=n;i++){
			for(auto p:vec[rk[i]]){
				s.insert(p);
			}
			int pos=*s.begin();
			if(rk[i])pos=vec[rk[i]][0];
			ans[pos]=i;
			s.erase(pos);
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);

	}


	return 0;
}
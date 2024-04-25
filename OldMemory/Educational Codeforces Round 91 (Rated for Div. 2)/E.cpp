#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
int t[maxn];
int a[maxn],b[maxn];
int cnt;
int fa[maxn],sz[maxn];
vector<int>vec[maxn];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=n;i++){
			scanf("%d",&t[i]);
			sz[t[i]]++;
			vec[t[i]].push_back(i);
		}
		for(int i=1;i<n;i++){
			if(t[i]==t[i+1]){
				fa[i]=i+1;
				cnt--;
			} 
		}
		printf("%d\n",cnt-1);
		for(int i=1;i<m;i++){
			scanf("%d%d",&a[i],&b[i]);
			sz[a[i]]+=sz[b[i]];
			sz[b[i]]=0;			
			if(sz[a[i]]>sz[b[i]])swap(a[i],b[i]);
			for(int j=0;j<sz[b[i]];j++){
				vec[a[i]].push_back(vec[b[i]][j]);
				int pj=find(vec[b[i]][j]);
				if()
			}
			vec[b[i]].clear();
		}
	}


	return 0;
}
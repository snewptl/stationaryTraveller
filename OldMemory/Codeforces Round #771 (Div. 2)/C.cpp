#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int fa[maxn],n,a[maxn],mx[maxn];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)fa[i]=i;
		int cur=a[n];
		mx[1]=a[1];
		for(int i=2;i<=n;i++)mx[i]=max(mx[i-1],a[i]);
		for(int i=n-1;i>=1;i--){
			if(a[i]>cur)fa[a[i]]=find(cur);
			if(i>1&&mx[i-1]>a[i]&&mx[i-1]>cur){
				fa[a[i]]=find(cur);
			}
			cur=min(a[i],cur);
		}
		int cnt=0;
		for(int i=1;i<=n;i++)if(fa[i]==i)cnt++;
		printf("%d\n",cnt);
	}


	return 0;
}
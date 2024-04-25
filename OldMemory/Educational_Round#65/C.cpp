#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int n,m;
int x,y,k;
int sum[maxn],ans[maxn];
int fa[maxn];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d",&k);
		if(k)scanf("%d",&x);
		for(int j=2;j<=k;j++){
			scanf("%d",&y);
			fa[find(y)]=find(x);
		}
	}
	for(int i=1;i<=n;i++){
		sum[find(i)]++;
	}
	for(int i=1;i<=n;i++){
		ans[i]=sum[find(i)];
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
    return 0;
}
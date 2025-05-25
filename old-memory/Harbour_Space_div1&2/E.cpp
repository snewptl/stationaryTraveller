#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
int n,m,tot;
int a[maxn],b[maxn],rk[maxn];
int cnt[maxn];
int vis[maxn],ans[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		tot=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)cnt[i]=0;
		for(int i=0;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];rk[b[i]]=i;
			cnt[(i-a[i]+n)%n]++;
		}
		int cur=0;
		for(int i=1;i<=n;i++){
			if(b[i]!=i){
				rk[b[i]]=rk[i];
				swap(b[rk[i]],b[i]);
				cur++;
			}
		}
		if(cur<=m)vis[0]=1;
		for(int i=1;i<n;i++){
			cur+=-cnt[i]+cnt[i-1];
			if(cur<=m)vis[i]=1;
		}
		for(int i=0;i<n;i++){
			if(vis[i])ans[++tot]=i;
		}
		printf("%d ",tot);
		for(int i=1;i<=tot;i++)printf("%d ",ans[i]);
		printf("\n");
    }
 
 
    return 0;
}
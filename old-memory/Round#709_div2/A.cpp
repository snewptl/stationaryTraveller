#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int ans[maxn];
int n,m,opt;
int k[maxn];
int vis[maxn];
int cnt[maxn];
vector<int>f[maxn];
bool cmp(int x,int y){
	return vis[x]<vis[y];
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
		opt=1;
        scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d",&k[i]);
			for(int j=1;j<=k[i];j++){
				int x;scanf("%d",&x);
				f[i].push_back(x);
				vis[x]++;
			}
		}
		for(int i=1;i<=m;i++){
			sort(f[i].begin(),f[i].end(),cmp);
			ans[i]=f[i][0];
			cnt[ans[i]]++;
		}
		for(int i=1;i<=n;i++){
			if(cnt[i]>(m+1)/2){
				int flag=cnt[i]-(m+1)/2;
				for(int j=1;j<=m;j++){
					if(ans[j]==i&&k[j]>=2){
						ans[j]=f[j][1];
						flag--;
						if(!flag)break;
					}
				}
				if(flag){
					opt=0;
				}
			}
		}
		if(opt){
			printf("YES\n");
			for(int i=1;i<=m;i++)printf("%d ",ans[i]);
			printf("\n");
		}
		else printf("NO\n");
		for(int i=1;i<=m;i++){
			f[i].clear();
		}
		for(int i=1;i<=n;i++){
			cnt[i]=0;vis[i]=0;
		}
    }


    return 0;
}
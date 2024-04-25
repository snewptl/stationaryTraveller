#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=2e5+10;
int n,m;
pii a[305];
int rk[305],pre[305];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d%d",&n,&m);
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int x;
				scanf("%d",&x);
				a[j]={x,m-j};
			}
		}
		sort(a+1,a+m+1);
		int ans=0;
		for(int i=1;i<=m;i++)rk[m-a[i].second]=i;
		for(int i=1;i<=m;i++){
			for(int j=1;j<rk[i];j++)ans+=pre[j];
			pre[rk[i]]=1;
		}
		printf("%d\n",ans);
    }


    return 0;
}
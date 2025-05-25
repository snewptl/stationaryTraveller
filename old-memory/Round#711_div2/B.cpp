#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
int w,a[maxn];
int vis[30];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&w);
        for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			for(int j=0;j<=20;j++){
				if((1<<j)&a[i])vis[j]++;
			}
		}
		int ans=0;
		while(n){
			int k=w;
			for(int i=20;i>=0;i--){
				int temp=min(k/(1<<i),vis[i]);
				vis[i]-=temp;
				k-=temp*(1<<i);
				n-=temp;
			}
			ans++;
		}
		printf("%d\n",ans);
    }


    return 0;
}
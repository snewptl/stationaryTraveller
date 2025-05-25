#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e2+10;
int vis[maxn][maxn];
int n,a[maxn],b[maxn];
int h[maxn];
int main(){
    int T=1;
    while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
			a[i]--;
		}
		for(int i=1;i<=n;i++)h[i]=i,vis[i][i]=b[i];
		for(int i=n;i>=1;i--){
			int now=i,col=i;
			while(a[i]>0){
				while(now<=n-1&&h[now+1]>h[now]){
					vis[now+1][col]=b[i];
					h[now+1]--;a[i]--;now++;
				}
				if(a[i]<=0)break;
				h[now]--;a[i]--;vis[now][--col]=b[i];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++)printf("%d ",vis[i][j]);
			printf("\n");
		}
    }


    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[1005][1005];
int vis[1005];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]>a[j][i]&&i<=j){
					if(!vis[i]&&!vis[j]){
						vis[i]=1;
						vis[j]=1;
						for(int k=1;k<=n;k++){
							swap(a[i][k])
						}
					}
				}
			}
		}
		
		
	}


	return 0;
}
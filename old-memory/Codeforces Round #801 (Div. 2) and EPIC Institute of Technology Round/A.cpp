#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
int a[55][55];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int mx=-1e9;
		int h=n,w=m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				if(mx<a[i][j]){
					h=max(i,n-i+1);
					w=max(j,m-j+1);
				}
				mx=max(a[i][j],mx);
			}
		}
		printf("%d\n",h*w);
		
	}


	return 0;
}
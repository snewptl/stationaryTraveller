#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e2+10;
int m,n;
int ans[maxn][maxn],a[maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans[i][j]=720720;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i%2+1;j<=m;j+=2){
			ans[i][j]+=pow(a[i][j],4);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}

    return 0;
}
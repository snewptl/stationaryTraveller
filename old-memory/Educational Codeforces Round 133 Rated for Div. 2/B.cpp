#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[105];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)a[i]=i;
		printf("%d\n",n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)printf("%d ",a[j]);
			puts("");
			swap(a[i],a[i+1]);
		}
	}


	return 0;
}
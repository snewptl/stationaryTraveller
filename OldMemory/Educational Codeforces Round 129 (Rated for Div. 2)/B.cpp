#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int a[maxn],n,m;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		int cur=0;
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			int x;
			scanf("%d",&x);
			cur+=x;
			cur%=n;
		}
		printf("%d\n",a[cur]);
	}


	return 0;
}
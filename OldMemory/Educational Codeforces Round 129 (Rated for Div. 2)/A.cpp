#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,a[maxn],b[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int mxa=0,mxb=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mxa=max(mxa,a[i]);
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d",&b[i]);
			mxb=max(mxb,b[i]);
		}
		if(mxa>=mxb)puts("Alice");
		else puts("Bob");
		if(mxb>=mxa)puts("Bob");
		else puts("Alice");

	}


	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,x,mn,mx,a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		mn=1e9,mx=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			mn=min(a[i],mn);
			mx=max(a[i],mx);
			if(mx-mn>2*x)ans++,mn=a[i],mx=a[i];
		}
		printf("%d\n",ans);
	}


	return 0;
}
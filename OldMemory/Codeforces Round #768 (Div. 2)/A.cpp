#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[maxn],b[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		int temp=0,mx=0;
		for(int i=1;i<=n;i++){
			temp=max(temp,min(a[i],b[i]));
			mx=max(mx,max(a[i],b[i]));
		}
		int ans=temp*mx;
		printf("%d\n",ans);
	}


	return 0;
}
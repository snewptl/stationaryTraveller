#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]<0)cnt++;
			a[i]=abs(a[i]);
		}
		int flag=1;
		for(int i=2;i<=cnt;i++){
			if(a[i]>a[i-1])flag=0;
		}
		for(int i=cnt+2;i<=n;i++){
			if(a[i]<a[i-1])flag=0;
		}
		if(flag)puts("YES");
		else puts("NO");
		

	}


	return 0;
}
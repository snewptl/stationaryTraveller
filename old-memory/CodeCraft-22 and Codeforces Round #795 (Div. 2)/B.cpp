#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn],p[maxn];
void solve(){
	int lst=n+1;
	for(int i=n;i>=1;i--){
		if(a[i]!=a[i-1]){
			for(int j=i;j<lst;j++){
				p[j]=j+1;
			}
			p[lst-1]=i;
			if(i==lst-1){
				puts("-1");
				return;
			}
			lst=i;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",p[i]);
	}
	puts("");
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve();
	}


	return 0;
}
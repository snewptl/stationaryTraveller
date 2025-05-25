#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[maxn];

int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int l=n-1,ans=0,r=n;
		while(l>=1){
			while(l>=1&&a[l]==a[r])l--;
			int frt=l+1-(r-l);
			for(int i=max(1,frt);i<=l;i++){
				if(a[i]!=a[r]){
					ans++;break;
				}
			}
			l=frt-1;
		}
		printf("%d\n",ans);
	}


	return 0;
}
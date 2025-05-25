#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k;
int a[maxn],ans;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			
		}
		for(int i=1;i<=n;i++){
			if(i>1&&i<n&&a[i]>a[i-1]+a[i+1])ans++;
		}
		if(k==1)printf("%d\n",(n-2+1)/2);
		else printf("%d\n",ans);
	}


	return 0;
}
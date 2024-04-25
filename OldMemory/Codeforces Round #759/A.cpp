#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn],ans;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		ans=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(ans==-1)continue;
			if(a[i]){
				if(i!=1&&a[i-1])ans+=5;
				else ans++;
			}
			else {
				if(i!=1&&!a[i-1]){
					ans=-1;
				}
			}
		}
		printf("%d\n",ans);
	}


	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int ans;
int n,m,cur,a[maxn];
void init(){
	ans=0;
	cur=m;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			if(cur<a[i])ans+=a[i]-cur,cur=0;
			else cur-=a[i];
		}
		printf("%d\n",ans);
	}


	return 0;
}
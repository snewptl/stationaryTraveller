#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,x,a[maxn];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1,cmp);
		int rem=0,ans=0;
		for(int i=1;i<=n;i++){
			rem++;
			if(1ll*rem*a[i]>=1ll*x)rem-=(x-1)/a[i]+1,ans++;
		}
		printf("%d\n",ans);
	}


	return 0;
}
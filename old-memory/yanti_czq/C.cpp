#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,k;
int a[maxn];
bool check(int n,int m){
	ll tot=0;
	for(int i=1;i<=k;i++){
		if(m-2<0)break;
		if(a[i]/n>1)tot+=a[i]/n-2,m-=2;
	}
	if(tot>=m)return true;
	else return false;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=k;i++)scanf("%d",&a[i]);
		sort(a+1,a+k+1);
		reverse(a+1,a+k+1);
		if(check(n,m)||check(m,n))puts("Yes");
		else puts("No");
	}


	return 0;
}
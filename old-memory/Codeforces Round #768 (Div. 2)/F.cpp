#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e6+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
int a[maxn],b[maxn];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)scanf("%d",&b[i]);
		int d=b[1];
		for(int i=1;i<=m;i++){
			d=gcd(d,b[i]);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=)
	}


	return 0;
}
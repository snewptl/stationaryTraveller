#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int a[maxn];
int n,l,r;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int l=1,r=n;
		while(l<=r&&a[l])l++;
		l--;
		while(r>=l&&a[r])r--;
		r++;
		printf("%d\n",r-l);
	}


	return 0;
}
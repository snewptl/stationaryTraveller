#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		cout<<a[n]+a[n-1]<<endl;
	}


	return 0;
}
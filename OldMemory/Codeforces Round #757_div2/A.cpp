#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,l,r,k;
int a[105];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		int cnt=0;
		scanf("%d%d%d%d",&n,&l,&r,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i]<l)continue;
			if(a[i]>r)break;
			if(k<a[i])break;
			k-=a[i];
			cnt++;
		}
		printf("%d\n",cnt);
	}


	return 0;
}
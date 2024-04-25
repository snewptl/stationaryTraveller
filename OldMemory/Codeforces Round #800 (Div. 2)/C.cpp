#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
bool solve(){
	ll sum=0;
	int ed=n;
	while(ed&&!a[ed])ed--;
	if(!ed)return true;
	for(int i=ed;i>=2;i--){
		sum+=a[i];
		if(sum>-1)return false;
	}	
	if(sum+a[1]!=0)return false;
	return true;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);

		if(solve())puts("YES");
		else puts("NO");
	}


	return 0;
}
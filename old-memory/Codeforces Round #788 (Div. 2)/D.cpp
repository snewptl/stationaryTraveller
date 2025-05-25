#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int sz,n;
ll dp[maxn];
void init(){
	for(int n=1;n<=2e5;n++){
		ll a=n/3,b=n/3,c=n/3;
		if(n%3==1)a++;
		if(n%3==2)a++,b++;
		dp[n]=(a*b+b*c+a*c)*2;
	}
	sz=2e5;
}
int main(){
	int T=1;scanf("%d",&T);
	init();
	while(T--){
		scanf("%d",&n);
		int pos=lower_bound(dp+1,dp+sz+1,n)-dp;
		printf("%d\n",pos);
	}


	return 0;
}
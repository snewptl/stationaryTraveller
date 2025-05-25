#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==1)puts("2");
		else if(n==2)puts("1");
		else {
			printf("%d\n",(n%3>0)+n/3);
		}
	}


	return 0;
}
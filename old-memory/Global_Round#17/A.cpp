#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(m==1&&n==1)printf("0\n");
		else if(min(m,n)==1)printf("1\n");
		else printf("2\n");

	}


	return 0;
}
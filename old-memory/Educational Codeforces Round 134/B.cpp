#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,sx,sy,d;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d%d%d%d",&n,&m,&sx,&sy,&d);
        if(max(min(sx-1,m-sy),min(n-sx,sy-1))>d)printf("%d\n",n+m-2);
        else puts("-1");
	}


	return 0;
}
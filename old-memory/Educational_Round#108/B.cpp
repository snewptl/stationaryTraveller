#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,m,k;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
		if(n>m)swap(n,m);
		int mn=(n-1)*n/2-1+n*(n+1)/2+(m-n)*n;
		int mx=m*n-1;
		if(mn<=k&&k<=mx)printf("YES\n");
		else printf("NO\n");
    }


    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
ll x[maxn],y[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld",&x[i],&y[i]);
		}
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		if(n%2){
			printf("1\n");
		}
		else {
			printf("%lld\n",(x[n/2+1]-x[n/2]+1)*(y[n/2+1]-y[n/2]+1));
		}
    }


    return 0;
}
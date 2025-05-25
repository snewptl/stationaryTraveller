#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll n;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
		ll temp=sqrt(n/2);
		ll temp2=sqrt(n/4);
		if((n%2==0&&temp*temp==n/2)||(n%4==0&&temp2*temp2==n/4))printf("YES\n");
		else printf("NO\n");
    }


    return 0;
}
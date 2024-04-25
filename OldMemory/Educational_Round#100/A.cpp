#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
typedef long long ll;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        ll a[4],sum=0;
		scanf("%lld%lld%lld",&a[1],&a[2],&a[3]);
		sort(a+1,a+4);
		sum=a[3]+a[1]+a[2];
		if(sum%9!=0||sum/9>a[1])printf("NO\n");
		else printf("YES\n");
    }


    return 0;
}
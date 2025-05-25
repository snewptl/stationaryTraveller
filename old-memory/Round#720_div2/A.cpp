#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll a,b;
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%lld%lld",&a,&b);
		// if(a%b==0)printf("NO\n");
		// else 
		if(b==1)printf("NO\n");
		else if(b==2)printf("YES\n%lld %lld %lld\n",a,a*3,a*4);
		else printf("YES\n%lld %lld %lld\n",a,a*(b-1),a*b);
    }


    return 0;
}
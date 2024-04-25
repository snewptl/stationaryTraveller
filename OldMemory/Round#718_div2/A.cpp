#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll n;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
		if(n%2050!=0)printf("-1\n");
		else {
			n/=2050;
			int temp=0;
			while(n){
				temp+=n%10;
				n/=10;
			}
			printf("%d\n",temp);			
		}

    }


    return 0;
}
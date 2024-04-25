#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("%lld\n",a+b+c-1);    
    }
   

    return 0;
}
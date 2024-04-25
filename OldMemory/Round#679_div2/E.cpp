#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d,ans;
ll get_num(ll k){
    return (k+1)*a-(1+k)*k/2*b*d;
}
void solve(ll l,ll r){
    while(l<r-1){
        ll lm=l+(r-l)/3,rm=r-(r-l)/3;
        if(get_num(lm)>=get_num(rm)){
            ans=max(get_num(rm),ans);
            r=rm-1;
        }
        else {
            ans=max(get_num(lm),ans);
            l=lm+1;
        }
    }
    ans=max(ans,max(get_num(l),get_num(r)));
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(a>b*c)printf("-1\n");
        else {
            ans=0;
            ll k=c/d;
            solve(0,k);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
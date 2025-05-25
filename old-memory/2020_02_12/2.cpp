#include<cstdio>
int n,g,b;
typedef long long ll;
int main(){
    int T;
    ll ans=0;
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d%d%d",&n,&g,&b);
        int len=n/2;
        ans=(ll)len/b*(g+b);
        if(ans>=n){printf("%d\n",n);}
        else {
            ans+=(ll)g+len%b;
            if(ans>=n){printf("%d\n",n);}
            else {
                int t=n-ans;
                ans+=(ll)b-len%b;
                ans+=(ll)t/g*(g+b);
                ans+=(ll)t%g;
                if(t%g==0)ans-=b;
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
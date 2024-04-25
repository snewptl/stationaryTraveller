#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n;
ll a[maxn],ans,t;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        ans=t=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        for(int i=1;i<n;i++){
            if(a[i]<0){
                if(abs(a[i])<=t)t-=abs(a[i]);
                else {
                    
                    ans+=abs(a[i])-t;t=0;
                }
            }
            if(a[i]>0)t+=a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
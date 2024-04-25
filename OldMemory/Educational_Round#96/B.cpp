#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,k;
ll a[maxn],ans;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);ans=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        sort(a+1,a+n+1);
        for(int i=n;i>=n-k;i--){
            ans+=a[i];
        }
        printf("%lld\n",ans);
    }

    return 0;
}
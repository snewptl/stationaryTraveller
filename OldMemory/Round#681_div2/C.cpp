#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
struct node{
    ll a,b;
}d[maxn];
bool cmp(node x,node y){
    return x.a==y.a?x.b<y.b:x.a<y.a;
}
ll ans,sum[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&d[i].a);
        for(int j=1;j<=n;j++)
            scanf("%lld",&d[j].b);
        sort(d+1,d+n+1,cmp);
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+d[i].b;
        }
        ans=sum[n];
        for(int i=1;i<=n;i++){
            ans=min(ans,max(sum[n]-sum[i],d[i].a));
        }
        printf("%lld\n",ans);
    }


    return 0;
}
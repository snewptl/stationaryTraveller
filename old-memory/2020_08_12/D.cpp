#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,d;
ll m;
ll a[maxn];
ll sum[maxn];
ll ans;
int main(){
    scanf("%d%d%lld",&n,&d,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int pos=1,k=0;
    while(pos<=n&&a[pos]<=m)pos++;
    if(pos==n+1)ans=sum[n];
    else for(int i=pos-1;i>=0;i--){
        ll tmp=sum[pos-1]-sum[pos-1-i];
        k=n-i;if((k-1)/(d+1)+pos>n)break;
        tmp+=sum[n]-sum[n-(k-1)/(d+1)-1];
        // tmp+=sum[pos-1-i]-sum[max(pos-1-i-(k-1)%(d+1),0)];
        ans=max(ans,tmp);
    }
    printf("%lld\n",ans);
    return 0;
}
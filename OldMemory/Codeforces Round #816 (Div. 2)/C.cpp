#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int pre[maxn],nxt[maxn];
int n,a[maxn];
ll ans;
int m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(i>1&&a[i]==a[i-1])pre[i]=pre[i-1];
        else pre[i]=i;
    }
    for(int i=1;i<n;i++){
        if(a[i]!=a[i+1])ans+=1ll*(n+1)*n/2-1ll*(n-i)*(n-i+1)/2-1ll*(pre[i]-1)*pre[i]/2;
    }
    ans+=1ll*(n+1)*n/2-1ll*(pre[n]-1)*pre[n]/2;
    for(int j=1;j<=m;j++){
        int i,x;
        scanf("%d%d",&i,&x);
        if(i>1&&a[i]==a[i-1]){
            if(i<n&&a[i]==a[i+1])
                ans+=1ll*(n+1)*n/2-1ll*(i+1)*i/2-1ll*(n-i+1)*(n-i+1+1)/2;
            else 
                ans-=1ll*(n-i+1)*(n-i+1+1)/2-1ll*(n-i)*(n-i+1)/2;
        }
        else {
            if(i<n&&a[i]==a[i+1])
                ans-=1ll*(i+1)*i/2-1ll*(i-1)*i/2;
            else ans-=1ll*n*(n+1)/2-1ll*(i-1)*i/2-1ll*(n-i)*(n-i+1)/2;
        }

        a[i]=x;
        if(i>1&&a[i]==a[i-1]){
            if(i<n&&a[i]==a[i+1])
                ans-=1ll*(n+1)*n/2-1ll*(i+1)*i/2-1ll*(n-i+1)*(n-i+1+1)/2;
            else 
                ans+=1ll*(n-i+1)*(n-i+1+1)/2-1ll*(n-i)*(n-i+1)/2;
        }
        else {
            if(i<n&&a[i]==a[i+1])
                ans+=1ll*(i+1)*i/2-1ll*(i-1)*i/2;
            else ans+=1ll*n*(n+1)/2-1ll*(i-1)*i/2-1ll*(n-i)*(n-i+1)/2;
        } 
        printf("%lld\n",ans);
    }

	return 0;
}
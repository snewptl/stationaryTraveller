#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxn=2e5+5;
const double eps=1e-10;
int n,k,a[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        ll sum=0,ans=0;
        for(int i=k*2+1;i<=n;i++)sum+=a[i];
        ans=sum;
        for(int i=k*2,j=n;i>=1;i-=2,j--){
            sum+=a[i]+a[i-1];
            sum-=a[j];
            ans=max(ans,sum);
        }
        cout<<ans<<'\n';

    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxn=4e5+5;
const double eps=1e-10;
int n,a[maxn],b[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=2*n;i++)cin>>a[i];
        sort(a+1,a+n*2+1);
        for(int i=1;i<=2*n;i++)b[i]=-1;
        b[n*2]=n;
        ll ans=1e18;
        if(n==1)ans=min(ans,(ll)abs(a[1]-a[2]));
        else {
            ll temp=0; 
            for(int i=1;i<=n*2;i++)temp+=abs(a[i]-b[i]);
            if(n%2==0)ans=min(ans,temp);
            temp=0;
            for(int i=1;i<=n*2;i++)temp+=abs(a[i]);
            ans=min(ans,temp);
            if(n==2){
                temp=0;
                for(int i=1;i<=n*2;i++)temp+=abs(a[i]-2);
                ans=min(ans,temp);
            }            
        }
        cout<<ans<<'\n';
    }   

    return 0;
}
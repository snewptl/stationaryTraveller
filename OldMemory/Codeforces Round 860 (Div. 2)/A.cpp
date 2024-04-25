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
int n,a[maxn],b[maxn];
pii it={0,0};
bool check(){
    for(int i=1;i<n;i++){
        if(a[i]>a[n])return false;
        if(b[i]>b[n])return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        it={0,0};
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=n;i++){
            int mx=max(a[i],b[i]);
            int mn=min(a[i],b[i]);
            a[i]=mx,b[i]=mn;
        }
        if(check())cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
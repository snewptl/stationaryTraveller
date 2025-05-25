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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        int l=1,r=n;
        while(l<=n&&a[l]==b[l])l++;
        while(r>=1&&a[r]==b[r])r--;
        int mn=a[l],mx=a[l];
        for(int i=l;i<=r;i++){
            mn=min(mn,a[i]);
            mx=max(mx,a[i]);
        }
        while(l>1&&a[l-1]<=mn)l--,mn=min(mn,a[l]);
        while(r<n&&a[r+1]>=mx)r++,mx=max(mx,a[r]);
        cout<<l<<" "<<r<<'\n';
    }

    return 0;
}
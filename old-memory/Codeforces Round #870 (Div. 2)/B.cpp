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
int n,a[maxn];
vector<int>vec;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        int gcd=0;
        for(int i=1;i<=n/2;i++){
            int temp=abs(a[i]-a[n-i+1]);
            gcd=__gcd(temp,gcd);
        }
        int flag=0;
        for(int i=1;i<=n/2;i++)if(a[i]!=a[n-i+1])flag=1;
        gcd*=flag;
        cout<<gcd<<'\n';
    }

    return 0;
}
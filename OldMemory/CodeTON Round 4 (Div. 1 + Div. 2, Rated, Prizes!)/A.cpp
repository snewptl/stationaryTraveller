#include<bits/stdc++.h>
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        int flag=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]<=i)flag=1;
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
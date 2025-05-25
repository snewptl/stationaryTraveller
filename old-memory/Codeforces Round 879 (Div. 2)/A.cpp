// cnt[1]  >= cmt[-1]
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
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        int x = 0, y = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int p; cin >> p;
            if (p == -1) ++x;
            else ++y;
        }
        int mn = n / 2;
        int res = 0;
        if (x > mn) res += x - mn, x = mn;
        if (x % 2) res++;
        cout << res <<'\n';
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod = 998244353;
const ll inf = 2e9;
const int maxn = 3e5+5;
const double eps = 1e-10;
vector<ll> dp[maxn], vec;
int a[maxn];
int n;
void clear() {
    for (int i = 1; i <= n; ++i) {
        dp[i].clear();
    }
    vec.clear();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1; cin >> T;
    while (T--) {
        cin >> n;
        clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            dp[i].push_back(a[i]);
        }
        for (int i = 2; i <= n; ++i) {
            for (auto it: dp[i - 1]) {
                ll d = __gcd(1ll * a[i], it), lcm = a[i] * it / d;
                if (lcm != dp[i].back() && lcm <= inf) dp[i].push_back(lcm);
            } 
        }
        for (int i = 1; i <= n; ++i) {
            for (auto it: dp[i]) vec.push_back(it);
        }
        sort(all(vec));
        vec.push_back(vec.back() + 2);
        if (vec[0] != 1) cout << 1 << '\n';
        else {
            for (int i = 1; i < vec.size(); ++i) {
                if(vec[i] - vec[i - 1] >= 2) {
                    cout << vec[i - 1] + 1 << '\n';   
                    break;
                }
            }
        }
    }
    return 0;
}
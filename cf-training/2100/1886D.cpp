#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, m;
ll quick_pow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x, res %= mod;
        x *= x, x %= mod;
        y /= 2;
    }
    return res;
}
ll inv(ll x) {
    return quick_pow(x, mod - 2);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        std::string s;
        std::cin >> s;
        ll ans = 1;
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == '?') ans *= i, ans %= mod;
        }
        if (s[0] == '?') std::cout << "0\n";
        else std::cout << ans << '\n';
        int flag = (s[0] == '?');
        for (int i = 1; i <= m; ++i) {
            int loc;
            char ch;
            std::cin >> loc >> ch;   
            --loc;
            if (s[loc] != ch) {
                if (s[loc] == '?') {
                    if (loc == 0) flag = 0;
                    else ans *= inv(loc), ans %= mod;
                } else if (ch == '?') {
                    if (loc == 0) flag = 1;
                    else ans *= loc, ans %= mod;
                }
            }
            s[loc] = ch;
            if (flag) std::cout << "0\n";
            else std::cout << ans << '\n';
        }
    }

    return 0;
}

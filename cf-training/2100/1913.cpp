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
const int maxn = 3e5 + 5;
const ll mod = 998244353;
int n;
int a[maxn];
void solve() {
    std::vector<pii> q;
    q.push_back({a[1], 1});
    ll sum = 1;
    for (int i = 2; i <= n; ++i) {
        ll val = 0;
        int flag = 1;
        while (!q.empty()) {
            pii it = q.back();
            if (it.first > a[i]) {
                q.pop_back();
                if (flag) {
                    flag = 0;
                    val += it.second;
                }
                val += it.second ;
                val %= mod;
                sum -= it.second;
                sum %= mod;
            } else {
                break;
            }
        }
        if (!q.empty() && !flag)val -= q.back().second * 2;
        val += sum;
        val %= mod;
        sum += val;
        sum %= mod;
        q.push_back({a[i], val});
    }
    std::cout << (sum + mod) % mod << '\n';
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        solve();
    }

    return 0;
}

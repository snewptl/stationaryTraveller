#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <cmath>
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
int s[maxn], t[maxn];
std::vector<pii> vec;
std::vector<pii> up, dn;
bool solve() {
    std::vector<std::pair<pii, int>> opt;
    while (!up.empty()) {
        if (dn.empty()) return false;
        auto u = up.back(); up.pop_back();
        auto v = dn.back(); dn.pop_back();
        if (s[u.second] < s[v.second]) return false;
        int delta = std::min(u.first, v.first);
        s[u.second] -= delta;
        s[v.second] += delta;
        if (u.first > v.first) {
            up.push_back({u.first - delta, u.second});
        } else if (u.first < v.first) {
            dn.push_back({v.first - delta, v.second});
        }
        opt.push_back({{v.second, u.second}, delta});
    }
    if (!dn.empty()) return false;
    std::cout << "YES\n";
    std::cout << opt.size() << '\n';
    for (auto [p, d] : opt) {
        auto [i, j] = p;
        std::cout << i << ' ' << j << ' ' << d << '\n';
    }
    return true;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];
        vec.push_back({s[i], i});
    }
    std::sort(all(vec));
    for (int i = 1; i <= n; ++i) {
        std::cin >> t[i];
    }
    std::sort(t + 1, t + n + 1);
    for (int i = n; i >= 1; --i) {
        auto [val, pos] = vec[i - 1];
        if (val > t[i]) {
            up.push_back({val - t[i], pos});
        } else if (val < t[i]) {
            dn.push_back({t[i] - val, pos});
        }
    }
    std::reverse(all(up));
    std::reverse(all(dn));
    if (!solve()) std::cout << "NO\n";

    return 0;
}
// 22 : 02 - 22 : 43
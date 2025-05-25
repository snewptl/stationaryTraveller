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
int n, m, k, a[maxn];
ll ans;
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        ans = 3e18;
        std::cin >> n >> m >> k;
        std::set<pii> s;
        std::vector<int> vec;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            s.insert({a[i], i});
        }
        int seg = (k + m - 1) / m;
        int count = 0;
        for (auto it : s) {
            vec.push_back(it.second);
            if (++count == seg) break;
        }
        sort(all(vec));
        ll sum = 0, remainder = k % m, additional = 1ll * m * m * (1ll * seg * (seg - 1) / 2);
        for (auto it : vec) sum += a[it];
        for (int i = 0; i < count; ++i) {
            ll res = 0;
            res = sum * m - (m - remainder) % m * 1ll * a[vec[i]];
            res += additional - (m - remainder) % m * (1ll * (count - 1 - i) * m + 1ll * i * m);
            ans = std::min(ans, res);
        }
        std::cout << ans << '\n';

    }

    return 0;
}

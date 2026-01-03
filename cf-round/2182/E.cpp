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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, m;
ll k;
int a[maxn];
int x[maxn];
ll y[maxn], z[maxn];
int count[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        int ans = 0;
        std::cin >> n >> m >> k;
        for (int i = 1; i <= m; ++i) count[i] = 0;
        for (int i = 1; i <= m; ++i) {
            std::cin >> a[i];
            count[a[i]] += 1;
        }
        std::vector<std::vector<pii>> vec;
        vec.resize(m + 1);
        std::set<int> remain;
        for (int i = 1; i <= n; ++i) {
            std::cin >> x[i] >> y[i] >> z[i];
            k -= y[i];
            z[i] -= y[i];
            vec[x[i]].push_back({z[i], i});
            remain.insert(i);
        }
        std::set<pli, std::greater<pli>> s;
        for (int i = 1; i <= m; ++i) {
            for (auto [price, id] : vec[i]) {
                s.insert({price, id});
            }
            while (count[i] && !s.empty()) {
                auto id = s.begin()->second;
                s.erase(s.begin());
                remain.erase(id);
                --count[i];
                ans += 1;
            }
        }
        std::vector<ll> price;
        for (auto it : remain) {
            price.push_back(z[it]);
        } 
        std::sort(all(price));
        for (auto it : price) {
            if (it <= k) {
                k -= it;
                ans += 1;
            } else {
                break;
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}

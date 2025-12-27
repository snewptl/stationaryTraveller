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
int a[maxn];
pii elf[maxn];
std::vector<pii> opt;
bool solve() {
    if (m == 0) {
        int cur = elf[n].first;
        for (int i = 1; i < n; ++i) {
            if (cur - elf[i].first > 0) {
                cur -= elf[i].first;
                opt.push_back({elf[i].second, elf[n].second});
            } else {
                for (int j = i; j <= n - 2; ++j) {
                    opt.push_back({elf[j].second, elf[j + 1].second});
                }
                opt.push_back({elf[n - 1].second, elf[n].second});
                return 1;
            }
        }
        return 0;
    } else {
        if (m * 2 > n) return 0;
        else {
            for (int i = n; i > m; i -= m) {
                for (int j = i; j > i - m && j - m >= 1; --j) {
                    opt.push_back({elf[j].second, elf[j - m].second});
                }
            }
            std::reverse(all(opt));
            return 1;
        }
    }
}
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
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            elf[i] = {a[i], i};
        }
        opt.clear();
        std::sort(elf + 1, elf + n + 1);
        if (solve()) {
            std::cout << opt.size() << '\n';
            for (auto [x, y] : opt) {
                std::cout << x << ' ' << y << '\n'; 
            }
        } else {
            std::cout << "-1\n";
        }
    }

    return 0;
}

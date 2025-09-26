#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
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
std::string str;
int a[maxn];
std::set<int> s, t;
int next_white(int x) {
    return *s.upper_bound(x);
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
        std::cin >> n >> m >> str;
        s.clear();
        t.clear();
        for (int i = 1; i <= 4 * (m + n); ++i) {
            s.insert(i);
        }
        for (int i = 1; i <= m; ++i) {
            std::cin >> a[i];
            s.erase(a[i]);
            t.insert(a[i]);
        }
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            if (str[i] == 'A') {
                cur += 1;
                t.insert(cur);
            } else {
                cur = next_white(cur);
                t.insert(cur);
                cur = next_white(cur);
            }
            while (*s.begin() <= cur) {
                s.erase(s.begin());
            }
        }
        std::cout << t.size() << '\n';
        for (auto it : t) {
            std::cout << it << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}

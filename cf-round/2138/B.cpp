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
const int maxn = 5e5 + 5;
const ll mod = 998244353;
int n, q;
int a[maxn];
int nxt[maxn][2];
int st[maxn][20];


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
        std::cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        std::vector<pii> vec;
        vec.push_back({0, n + 1});
        nxt[n + 1][0] = nxt[n + 1][1] = n + 1;
        for (int i = n; i >= 1; --i) {
            while (vec.back().first > a[i]) {
                vec.pop_back();
            }
            nxt[i][0] = vec.back().second;
            vec.push_back({a[i], i});
        }
        std::set<pii> s;
        s.insert({a[n], n + 1});
        nxt[n][1] = n + 1;
        for (int i = n - 1; i >= 1; --i) {
            auto it = s.lower_bound({a[i], 0});
            if (it == s.begin()) {
                nxt[i][1] = n + 1;
            } else {
                --it;
                nxt[i][1] = it->second;
            }
            while (!s.empty()) {
                auto it = s.lower_bound({a[i], 0});
                if (it != s.end() && it->second >= nxt[i][0]) {
                    s.erase(it);
                } else {
                    break;
                }
            }
            it = s.lower_bound({a[i], 0});
            if (it == s.begin()) {
                s.insert({a[i], nxt[i][0]});
            } else {
                --it;
                if (it->second > nxt[i][0]) {
                    s.insert({a[i], nxt[i][0]});
                }
            }
            
        }

        for (int j = 0; j < 20; ++j) {
            for (int i = 1; i <= n + 1; ++i) {
                st[i][j] = n + 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            st[i][0] = nxt[i][1];
        }
        for (int j = 1; j < 20; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (i + (1 << j) - 1 <= n) st[i][j] = std::min(st[i + (1 << (j - 1))][j - 1], st[i][j - 1]);
            }
        }
        
        while (q--) {
            int l, r;
            std::cin >> l >> r;
            int dep = std::__lg(r - l + 1);
            int pos = std::min(st[l][dep], st[r - (1 << dep) + 1][dep]);
            if (pos > r) std::cout << "YES\n";
            else std::cout << "NO\n";
        }
    }

    return 0;
}

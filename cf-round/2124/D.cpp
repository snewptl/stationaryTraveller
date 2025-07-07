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
int n, k, a[maxn];
std::vector<std::vector<int>> vec;
std::vector<int> frame;
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
        std::cin >> n >> k;
        vec.clear();
        vec.resize(n + 1);
        frame.clear();
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            vec[a[i]].push_back(i);
        }
        int sz = 0, last = 0;
        for (int i = 1; i <= n; ++i) {
            if (vec[i].size() + sz < k) {
                sz += vec[i].size();
                for (auto it : vec[i]) {
                    frame.push_back(it);
                }
            } else {
                last = i;
                break;
            }
        }
        std::sort(all(frame));
        int place = sz;
        int flag = 1;
        for (int i = 0; i < sz / 2; ++i) {
            if (a[frame[i]] != a[frame[sz - 1 - i]]) flag = 0;
        }
        if (flag) {
            for (int i = last; i <= n; ++i) {
                if (!vec[i].empty()) {
                    std::set<int> s;
                    for (auto it : vec[i]) {
                        s.insert(it);
                    }
                    while (!s.empty()) {
                        auto cur = *s.begin(); s.erase(cur);
                        int idx = std::lower_bound(all(frame), cur) - frame.begin();
                        if (idx > place / 2) break;
                        if (place % 2 == 0 && idx == place / 2) {
                            ++sz;
                        } else if (!s.empty()) {
                            auto it = s.lower_bound(frame[place - 1 - idx]);
                            if (it != s.end()) {
                                if (idx == 0 || *it < frame[place - idx]) {
                                    sz += 2;
                                }
                                s.erase(it);
                            }
                        }
                    }
                    break;
                }
            }
        }
        if (sz < k - 1 || !flag) std::cout << "NO\n"; 
        else std::cout << "YES\n";
    }

    return 0;
}

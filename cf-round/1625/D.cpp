#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 3e5 + 5;
const ll mod = 998244353;
int n, k, len;
int a[maxn];
std::unordered_map<int, std::set<pii>> mp;
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
        std::cin >> n >> k;

        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        if (k == 0) {
            std::cout << n << '\n';
            for (int i = 1; i <= n; ++i) {
                std::cout << i << ' ';
            }
            std::cout << '\n';
        } else {
            std::vector<int> ans;
            int len = std::__lg(k);
            for (int i = 1; i <= n; ++i) {
                int mask = (1 << (len + 1)) - 1;
                mp[a[i] >> (len + 1)].insert({a[i] & mask, i});
            }
            for (auto [_, s] : mp) {
                if (s.size() == 1) {
                    ans.push_back(s.begin()->second);
                    continue;
                }
                std::vector<pii> seg;
                int flag = 0;
                for (auto [val, ind] : s) {
                    int cur = 0;
                    for (int j = len; j >= 0; --j) {
                        if ((1 << j) & k) {
                            if ((1 << j) & val) {
                                cur |= 0;
                            } else {
                                cur |= 1 << j;
                            }
                        } else {
                            pii p;
                            if ((1 << j) & val) {
                                p = {cur, cur + (1 << j) - 1};
                                cur |= 1 << j;
                            } else {
                                p = {cur + (1 << j), cur + (1 << (j + 1)) - 1};
                                cur |= 0;
                            }
                            auto it = s.lower_bound({p.first, 0});
                            if (it != s.end() && it->first <= p.second) {
                                ans.push_back(ind);
                                ans.push_back(it->second);
                                flag = 1;
                                break;
                            }
                        }
                    }
                    if (flag) break;
                    else {
                        pii p = {cur, cur};
                        auto it = s.lower_bound({p.first, 0});
                        if (it != s.end() && it->first <= p.second) {
                            ans.push_back(ind);
                            ans.push_back(it->second);
                            flag = 1;
                            break;
                        }
                    }
                }
                if (!flag) {
                    ans.push_back(s.begin()->second);
                }

            }
            if (ans.size() < 2) std::cout << "-1\n";
            else {
                std::cout << ans.size() << '\n';
                for (auto it : ans) {
                    std::cout << it << ' ';
                }
                std::cout << '\n';
            }

        }
        
    }

    return 0;
}

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
int l, r, n;
int a[maxn];
int p2[maxn];
int ori[20], modi[20];
std::vector<int> vec;
int ans[20];
int prefix[maxn];
bool is_out(int x) {
    return x > r || x < l;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    p2[0] = 1;
    for (int j = 1; j <= 20; ++j) 
    p2[j] = p2[j - 1] * 2;
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> l >> r;
        n = r - l + 1;
        vec.clear();
        for (int i = 0; i < 17; ++i) {
            ori[i] = modi[i] = ans[i] = 0;
        }
        for (int i = l; i <= r; ++i) {
            for (int j = 0; j < 17; ++j) {
                if (i & p2[j]) {
                    ori[j] += 1;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            for (int j = 0; j < 17; ++j) {
                if (a[i] & p2[j]) {
                    modi[j] += 1;
                }
            }
        }
        for (int i = 16; i >= 0; --i) {
            if (ori[i] == modi[i]) {
                if (ori[i] != n / 2) {
                    ans[i] = 0;
                } else {
                    vec.push_back(i);
                }
            } else {
                ans[i] = 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 17; ++j) {
                if (ans[j]) {
                    a[i] ^= p2[j];
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            int cur = a[i];
            for (auto it : vec) {
                if (is_out(cur)) ans[it] = 1, cur ^= p2[it];
                else {
                    if (is_out(cur ^ p2[it])) {
                        ans[it] = 0;
                    } else {
                        break;
                    }
                }
            }
        }
        int fin = 0;
        for (int i = 0; i < 17; ++i) {
            if (ans[i]) fin |= p2[i];
        }
        std::cout << fin << '\n';
        
    }

    return 0;
}
// 12 : 25 - 
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
const int maxn = 4e5 + 5;
const ll mod = 998244353;
std::map<int, int> mp;
int n, len, max, wide, high;
int prefix[maxn], suffix[maxn], count[maxn];
std::vector<std::vector<int>> a;
std::vector<int> vec;
std::set<pii> s;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        mp.clear();
        max = 0;
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            int x;
            std::cin >> x;
            mp[x] += 1;
        }
        int len = sqrt(n + 1);
        if (len * len > n) --len; 
        for (int i = 0; i <= len + 1; ++i) {
            prefix[i] = suffix[i] = count[i] = 0;
        }
        for (auto &[_, val] : mp) {
            if (val > len) val = len;
            count[val] += 1;
        }
        for (int i = 1; i <= len; ++i) {
            int j = n / i;
            if (j < i) break;
            prefix[i] = prefix[i - 1] + (i - 1) * count[i - 1];
        }
        for (int i = len; i >= 1; --i) {
            int j = n / i;
            if (j < i) continue;
            suffix[i] = suffix[i + 1] + count[i];
        }
        for (int i = 1; i <= len; ++i) {
            int j = n / i;
            if (j < i) break;
            assert(suffix[i] <= j);
            int cur = prefix[i] + suffix[i] * i;
            cur -= cur % i;
            if (cur / i >= i && cur > max) max = cur, wide = i, high = cur / i;
        }
        vec.clear();
        s.clear();
        for (auto &[key, val] : mp) {
            if (val > wide) val = wide;
            s.insert({val, key});
        }
        for (auto [val, key] : s) {
            for (int i = 1; i <= val; ++i) {
                vec.push_back(key);
            }
        }
        a.clear();
        a.resize(wide);
        for (int i = 0; i < wide; ++i) {
            a[i].resize(high, 0);
        }
        for (int j = 0; j < high; ++j) {
            int row = 0, col = j;
            while (row < wide) {
                a[row][col] = vec.back();
                vec.pop_back();
                row += 1;
                col = (col + 1) % high;
            }
        }
        std::cout << wide * high << "\n" << wide << ' ' << high << '\n';
        for (int i = 0; i < wide; ++i) {
            for (int j = 0; j < high; ++j) {
                std::cout << a[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

    return 0;
}
// 15 : 05 - 16 : 48
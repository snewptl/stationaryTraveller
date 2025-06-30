#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
int n, m, q;
std::set<int> vec[maxn];
int count[maxn * 3];
int used[maxn * 3];
int fw[maxn * 3];
int lowbit(int x) {
    return x & (-x);
}
void update(int x, int val) {
    for (int i = x; i <= n * 3; ++i) {
        fw[i] += val;
    }
}
int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) {
        res += fw[i];
    }
    return res;
}
int find_near(int i, int h) {
    if (h == 1) return i + query(i);
    return find_near(find_near(i, h - 1), 1);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int flag = 1;
    std::cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i) vec[i].insert(0);
    for (int i = 1; i <= q; ++i) {
        int x, y[4];
        std::cin >> x;
        int max = 0;
        for (int j = 1; j <= 3; ++j) {
            std::cin >> y[j];
            max = std::max(max, y[j] + *vec[j + x - 1].rend());
        }
        for (int j = 1; j <= 3; ++j) {
            for (int t = 1; t <= y[j]; ++t) {
                int new_h = find_near(max - y[j] + 1, t);
                if (new_h > find_near(n, 1)) flag = 0;
                count[new_h] += 1;
                vec[j + x - 1].insert(new_h);
            }
        }
        for (int j = 1; j <= 3; ++j) {
            for (int t = 1; t <= y[j]; ++t) {
                int new_h = find_near(max - y[j] + 1, t);
                if (count[new_h] == m) {
                    if (used[new_h]) continue;
                    used[new_h] = 1;
                    update(new_h, 1);
                    for (int i = 1; i <= m; ++i) {
                        vec[i].erase(new_h);
                    }
                } 
            }
        }

        if (!flag) {
            std::cout << i << '\n';
            break;
        }
    }
    if (flag) std::cout << "-1\n";
    return 0;
}

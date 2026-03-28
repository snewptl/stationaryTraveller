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
int n, k;
int a[maxn], b[maxn];
int type[maxn];
int val_a[maxn], val_b[maxn];
int count_a[maxn], count_b[maxn];
bool solve() {
    for (int i = 1; i <= n; ++i) {
        int cur = (i - 1) % k;
        if (val_a[cur] && a[i] != val_a[cur]) {
            type[cur] = 1;
        }
        val_a[cur] = a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (b[i] == -1) continue;
        int cur = (i - 1) % k;
        if (val_b[cur] && b[i] != val_b[cur]) {
            type[cur] = 1;
        }
        val_b[cur] = b[i];
    }
    for (int i = 1; i <= n; ++i) {
        int cur = (i - 1) % k;
        if (type[cur]) {
            if (type[cur] == 1) {
                if (b[i] != -1 && b[i] != a[i]) return false;
            } else {
                if (a[i] != val_a[cur]) return false;
                if (b[i] != -1 && b[i] != val_b[cur]) return false;
            }
        } else {
            if (b[i] != -1) {
                if (a[i] == b[i]) type[cur] = 1;
                else type[cur] = 2;
                val_b[cur] = b[i];
            }
        }
    }
    int free_count = 0;
    for (int i = 1; i <= k; ++i) {
        int cur = i - 1;
        count_a[a[i]] += 1;
        if (!type[cur]) free_count += 1;
        else {
            if (type[cur] == 1) {
                count_b[a[i]] += 1;
            } else {
                count_b[val_b[cur]] += 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int up = count_a[i], dn = count_b[i];
        if (up < dn) return false;
        if (up - dn > free_count) return false;
        free_count -= up - dn;
    }
    return true;
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
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
        }
        for (int i = 0; i < k; ++i) {
            type[i] = 0;
            val_a[i] = val_b[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            count_a[i] = count_b[i] = 0;
        }
        if (solve()) std::cout << "YES\n";
        else std::cout << "NO\n";

    }

    return 0;
}

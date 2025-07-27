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
int n;
ll k;
ll a[maxn], b[maxn];
ll break_a[maxn * 2], sum_a[maxn * 2], sum_b[maxn * 2];
ll break_b[maxn * 2];
bool is_greater(int l, int r) {
    return sum_a[r] - sum_a[l - 1] > sum_b[r] - sum_b[l - 1];
}
void init() {
    for (int i = 0; i < n * 2; ++i) {
        break_a[i + 1] = a[i % n];
        break_b[i + 1] = b[i % n];
    }
    for (int i = 1; i <= n * 2; ++i) {
        sum_a[i] = sum_a[i - 1] + break_a[i];
        sum_b[i] = sum_b[i - 1] + break_b[i];
    }
}
bool check(int len) {
    init();
    int start = 1;
    while (is_greater(start, start + len - 1)) ++start;
    ++start;
    assert(start <= n + 1);
    for (int i = start, j = 0; j < n; ++i, ++j) {
        a[j] = break_a[i];
        b[j] = break_b[i];
    }
    init();
    for (int i = n; i >= 1; --i) {
        if (is_greater(i, i + len - 1)) {
            
        }
    }
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
        std::cin >> n >> k;
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> b[i];
        int l = 0, r = n, ans = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        std::cout << ans << '\n';
    }

    return 0;
}

// 12 : 25 - 12 : 58  33min
// 15 : 24 - 15 : 57 34min
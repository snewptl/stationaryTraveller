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
int n;
ll a[maxn], pre[maxn], nxt[maxn];
ll sum[2];
bool solve() {
    if (sum[0] == sum[1]) {
        ll last = a[1];
        for (int i = 2; i <= n; ++i) {
            if (a[i] < last) return false;
            last = a[i] - last;
        }
        return true;
    } else {
        for (int i = 1; i <= n; ++i) {
            pre[i] = a[i] - pre[i - 1];
        }
        for (int i = n; i >= 1; --i) {
            nxt[i] = a[i];
            if (i != n) nxt[i] -= nxt[i + 1];
        }
        nxt[n + 1] = 0;
        int start = n, end = 1;
        for (int i = 1; i <= n; ++i) {
            if (pre[i] < 0) {
                start = i;
                break;
            }
        }
        for (int i = n; i >= 1; --i) {
            if (nxt[i] < 0) {
                end = i;
                break;
            }
        }
        if (start < end - 1) return false;
        if (start == end - 1) end = start;
        else if (start == end) start = std::max(start - 1, 0), end = std::min(start + 1, n - 1);
        else 

        if (vec.size() == 2) {
            if (vec[0] != vec[1] - 1) return false;
            start = vec[0], end = vec[0];
        } else if (vec.size() == 1){
            start = std::max(vec[0] - 1, 0);
        }
        for (int i = start; i <= end; ++i) {
            std::swap(a[i], a[i + 1]);
            if (a[i] >= pre[i - 1] && a[i + 1] - (a[i] - pre[i - 1]) >= 0 && nxt[i + 2] == a[i + 1] - (a[i] - pre[i - 1])) {
                return true;
            }
            std::swap(a[i], a[i + 1]);
        }
        return false;
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
        std::cin >> n;
        for (int i = 0; i < 2; ++i) sum[i] = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            sum[i % 2] += a[i];
        }
        std::cout << (solve() ? "YES\n" : "NO\n");
    }

    return 0;
}

// 16 : 34 - 17 : 11 - 37min 
// 18 : 17 - 18 : 26 - 19min
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
int p[maxn], vis[maxn];
int count[maxn];
bool bob() {
    int sum = 0;
    int remain = k;
    for (int i = k + 1; i >= 2; --i) {
        if (!remain) break;
        for (int j = 1; j <= count[i]; ++j) {
            if (!remain) break;
            sum += i - 1;
            remain -= 1;
        }
    }
    if (sum > k) return false;
    return true;
}
bool alice(int x, int min) {
    // std::cout << x << ' ' << min << '\n';
    if (x != k || count[1]) {
        if(bob()) return true;
    }  
    for (int i = min; i <= x; ++i) {
        if (!count[i]) continue;
        count[i] -= 1;
        if (alice(x - i, i)) return true;
        count[i] += 1;
    }
    return false;

}
bool solve() {
    for (int i = k + 2; i <= n; ++i) {
        if (count[i]) return false;
    }
    if (alice(k, 2)) {
        if (count[k + 1]) {
            int remain = n - (k + 1);
            if (remain <= k) return true;
            else if ((remain - k) % 2) return false;
            else return true;
        }
        return true;
    }
    return false;
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
            std::cin >> p[i];
        }
        for (int i = 1; i <= n; ++i) {
            vis[i] = 0;
        }
        for (int i = 0; i <= n; ++i) {
            count[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            int cur = i, size = 0;
            while (!vis[cur]) {
                vis[cur] = 1;
                size += 1;
                cur = p[cur];
            }
            count[size] += 1;
        }
        if(solve()) std::cout << "Alice\n";
        else std::cout << "Bob\n";
    }

    return 0;
}

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
int n, h, m, k;
pii train[maxn];
std::map<int, int> prefix;
void add(int l, int r) {
    if (l < 0) {
        prefix[l + m] += 1;
        prefix[0] += 1;
        prefix[r + 1] -= 1;
    } else if (r >= m) {
        prefix[l] += 1;
        prefix[0] += 1;
        prefix[r - m + 1] -= 1;
    } else {
        prefix[l] += 1;
        prefix[r + 1] -= 1;
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> h >> m >> k;
    for (int i = 1; i <= n; ++i) std::cin >> train[i].first >> train[i].second;
    for (int i = 1; i <= n; ++i) {
        int p = train[i].second;
        add(p - m / 2, p - k);
        add(p, p + m / 2 - k);
    }
    int ans = 0, last = -1, p = 0;
    for (auto &[it, val] : prefix) {
        if (last != -1) val += prefix[last];
        if (ans < val) {
            ans = val;
            p = it;
        }
        last = it;
    }
    std::vector<int> vec;
    for (int i = 1; i <= n; ++i) {
        if (check(train[i].second, )) {
            
        }
    }
    std::cout << n - ans << '\n';
    
    return 0;
}
// 17 : 10 - 
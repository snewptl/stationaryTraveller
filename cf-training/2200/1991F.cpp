#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
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
int n, q;
int a[maxn];
pii questions[maxn];
void solve() {
    
    std::set<int> s;
    for (int i = 1; i <= n; ++i) s.insert({})
    pii cur = {1, 0};
    for (int i = 1; i <= q; ++i) {
        while(cur.second < )
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
        std::cin >> n >> q;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        for (int i = 1; i <= q; ++i) {
            int l, r;
            std::cin >> l >> r;
            questions[i] = {l, r};
        }
        std::sort(questions + 1, questions + q + 1);
        solve();
    }

    return 0;
}

// 20 min
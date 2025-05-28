#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n;
int ask (int l, int r) {
    if (l == r) return 0;
    std::cout << "? " << l << " " << r << '\n';
    std::cout.flush();
    int x;
    std::cin >> x;
    return x;
}

int solve (int l, int r) {
    if (l == r) return l;
    int mid = l + r >> 1;
    int idx_left = solve(l, mid);
    int idx_right = solve(mid + 1, r);
    int pre = ask(idx_left, idx_right - 1);
    int nxt = ask(idx_left, idx_right);
    if (pre == nxt) return idx_right;
    else return idx_left;
}
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        int res = solve(1, n);
        std::cout << "! " << res << '\n';    
        std::cout.flush();
    }

    return 0;
}

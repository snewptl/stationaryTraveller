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
int ask(int l, int r) {
    std::cout << "? " << r - l + 1  << ' ';
    for (int i = l; i <= r; ++i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    int res;
    std::cin >> res;
    return res;
}
void solve() {
    int l = 3, r = n;
    std::vector<int> vec;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ask(1, mid - 1) < ask(mid, n)) r = mid + 1, res = mid;
        else l = mid - 1;
    }
    vec.push_back(res);
    
    if (res != n || ask(1, res + 1) > ask(res + 2, n)) {
        l = res + 2, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if () l = mid + 1, res = mid;
            else r = mid - 1;
        }
        vec.push_back(res);
        l = vec[0] + 1, r = vec[1] - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (dir2(mid)) l = mid + 1, res = mid;
            else r = mid - 1;
        }
        vec.push_back(res);
    } else {
        l = 1, r = res - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (dir2(mid)) l = mid + 1, res = mid;
            else r = mid - 1;
        }
        vec.push_back(res);
        l = 1, r = res - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (dir3(mid)) l = mid + 1, res = mid;
            else r = mid - 1;
        }
        vec.push_back(res);

    }
    std::cout << "! " << vec[2] << ' ' << vec[1] << ' ' << vec[0] << std::endl;
}
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        n = 2 * n + 1;
        solve();
    }

    return 0;
}

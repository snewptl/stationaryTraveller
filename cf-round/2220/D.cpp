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
int ask(int l, int r, std::vector<int> appendlist) {
    int sz = r - l + 1 + appendlist.size();
    if (sz <= 0) {
        return 0;
    }
    std::cout << "? " << sz  << ' ';
    for (int i = l; i <= r; ++i) {
        std::cout << i << ' ';
    }
    for (auto it : appendlist) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;
    int res;
    std::cin >> res;
    return res;
}
void solve() {
    int l = 1, r = n;
    std::vector<int> vec, appendlist;
    int pos = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int resl = ask(1, mid, appendlist), lenl = mid + appendlist.size();
        if ((lenl - resl) % 2) r = mid - 1, pos = mid;
        else l = mid + 1;
    }
    vec.push_back(pos);
    appendlist.push_back(pos);
    l = 1, r = pos - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int resl = ask(1, mid, appendlist), lenl = mid + appendlist.size();
        if ((lenl - resl) % 2) r = mid - 1, pos = mid;
        else l = mid + 1;
    }
    vec.push_back(pos);
    appendlist.push_back(pos);
    l = 1, r = pos - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int resl = ask(1, mid, appendlist), lenl = mid + appendlist.size();
        if ((lenl - resl) % 2) r = mid - 1, pos = mid;
        else l = mid + 1;
    }
    vec.push_back(pos);
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

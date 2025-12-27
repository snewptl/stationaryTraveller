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
ll ask(int l, int r) {
    std::cout << "? " << l << ' ' << r << '\n';
    std::cout.flush();
    ll res;
    std::cin >> res;
    return res;
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
        int l = 1, r = n;
        ll last = ask(l, r);
        while (l < r) {
            ll to = last / 2;
            int curl = l, curr = r, mid = l;
            while (curl <= curr) {
                mid = (curl + curr) / 2;
                ll temp = ask(l, mid);
                if (temp == to) {
                    break;   
                } else if (temp < to) {
                    curl = mid + 1;
                } else {
                    curr = mid - 1;
                }
            }
            if (mid - l + 1 < r - mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
            last = to;
        }
        std::cout << "! " << last << '\n';
        std::cout.flush();
    }

    return 0;
}

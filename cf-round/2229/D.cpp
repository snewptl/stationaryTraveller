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
const int maxn = 1e5 + 5;
const ll mod = 998244353;
int n;
int a[maxn], b[maxn];
int up[maxn], dn[maxn];
std::vector<std::pair<int, pii>> vec;
bool check(int id) {
    for (int i = 1; i <= n; ++i) {
        if (a[i] < vec[id].first) up[i] = -1;
        else if (a[i] > vec[id].first) up[i] = 1;
        else up[i] = 1;
        if (b[i] < vec[id].first) dn[i] = -1;
        else if (b[i] > vec[id].first) dn[i] = 1;
        else dn[i] = 1;
    }
    int posi = 0, neg = 0;
    int last = 1;
    for (int i = 1; i <= n; ++i) {
        if (up[i] * dn[i] == 1) {
            if (up[i] == 1) {
                posi += 1;
                last = 1;
            } else {
                if (last) neg += 1;
                last = 0;
            }
        }
    }
    return posi > neg;

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
        std::cin >> n;
        vec.clear();
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            vec.push_back({a[i], {i, 0}});
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
            vec.push_back({b[i], {i, 1}});
        }
        std::sort(all(vec));
        int l = 0, r = vec.size() - 1;
        int ans = vec[0].first;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) ans = vec[mid].first, l = mid + 1;
            else r = mid - 1;
        }
        std::cout << ans << '\n';
    }

    return 0;
}

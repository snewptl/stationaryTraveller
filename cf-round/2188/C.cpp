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
int A[maxn], a[maxn];
std::set<pii> s;
int Min, Max;
bool check(int x) {
    s.clear();
    for (int i = 1; i <= n; ++i) {
        a[i] = A[i];
        s.insert({a[i], i});
    }
    for (int i = 1; i <= n; ++i) {
        auto [val, pos] = *s.begin();
        s.erase(s.begin());
        if (a[i] == val) {
            assert(pos == i);
        } else {
            int min = val, max = a[i];
            if (max - min >= x || min - Min >= x || Max - max >= x) {
                s.erase({max, i});
                a[pos] = max;
                a[i] = min;
                s.insert({max, pos});
            } else {
                return false;
            }
        }
    }
    return true;
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
        Min = 1e9;
        Max = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> A[i];
            a[i] = A[i];
            Min = std::min(A[i], Min);
            Max = std::max(A[i], Max);
        }
        std::sort(a + 1, a + n + 1);
        int ans = 1e9;
        for (int i = 1; i <= n; ++i) {
            if (a[i] != A[i]) {
                ans = std::min(std::max(A[i] - Min, Max - A[i]), ans);
            }
        }
        if (ans == 1e9) ans = -1;
        std::cout << ans << '\n';
    }

    return 0;
}

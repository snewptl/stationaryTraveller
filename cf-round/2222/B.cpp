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
int n, m;
ll a[maxn];
int x[maxn];
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
        std::cin >> n >> m;
        std::vector<ll> vec[2];
        ll sum = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            sum += a[i];
            vec[i % 2].push_back(a[i]);
        } 
        int count[2] = {0, 0};
        for (int i = 1; i <= m; ++i) {
            std::cin >> x[i];
            count[x[i] % 2] += 1;
        }
        for (int i = 0; i < 2; ++i) {
            std::sort(all(vec[i]));
            std::reverse(all(vec[i]));
            if (vec[i].empty()) continue;
            if (!count[i]) continue;
            if (vec[i][0] <= 0) {
                sum -= vec[i][0];
            } else {
                for (auto it : vec[i]) {
                    if (it <= 0 || count[i] <= 0) break;
                    sum -= it;
                    --count[i];
                }

            }
        }
        std::cout << sum << '\n';
        
    }

    return 0;
}

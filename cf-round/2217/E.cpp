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
int p[maxn], q[maxn], d[maxn];
bool solve() {
    q[n] = 1;
    if (d[n] != 0) return false;
    for (int i = n - 1; i >= 1; --i) {
        int count = 0;
        std::vector<int> vec;
        for (int j = i + 1; j <= n; ++j) {
            if (p[i] < p[j]) {
                count += 1;
                // if (vec.size() < d[i])
                vec.push_back(q[j]);
            }
        }
        if (count < d[i]) return false;
        if (d[i] == 0) {
            q[i] = n - i + 1;
        } else {
            int to;
            if (count) {
                std::sort(all(vec));
                to = vec[vec.size() - d[i]];
            } else {
                to = 1;
            }
            for (int j = i + 1; j <= n; ++j) {
                if (q[j] >= to) q[j] += 1;
            }
            q[i] = to;
        }
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << q[i] << ' ';
    }
    std::cout << '\n';
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
        for (int i = 1; i <= n; ++i) {
            std::cin >> p[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> d[i];
        }
        if (!solve()) std::cout << "-1\n";
    }

    return 0;
}

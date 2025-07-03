#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
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
int n;
std::string str;
int vis[maxn];
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
        std::cin >> n >> str;
        for (int i = 0; i < n; ++i) {
            if (str[i] == 'A') vis[i + 1] = 0;
            else vis[i + 1] = 1;
        }
        int sum[2] = {0, 0};
        for (int i = 1; i <= n; ++i) {
            sum[vis[i]] += 1;
        }
        int flag;
        if (n == 2) {
            if (vis[1] == 0) flag = 0;
            else flag = 1;
        } else {
            if (std::min(sum[1], sum[0]) == 1) {
                if (sum[0] == 1) flag = 1;
                else flag = 0;
            } else if (vis[1] == vis[n]) {
                if (vis[1] == 0) flag = 0;
                else flag = 1;
            } else if (vis[n] == 1) {
                flag = 1;
            } else {
                if (vis[n - 1] == 0) flag = 0;
                else flag = 1;
            }
        }
        std::cout << (!flag ? "Alice" : "Bob") << '\n';
    }

    return 0;
}

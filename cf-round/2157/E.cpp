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
int n, k;
int count[maxn * 2];
std::vector<int> stack;
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
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            int x; std::cin >> x;
            count[x] += 1;
        }
        stack.clear();
        for (int i = n * 3; i > n * 2; --i) {
            stack.push_back(i);
        }
        int ans = 0;
        for (int i = n * 2; i >= 1; --i) {
            
            int cur = count[i];
            if (cur > k) {
                while (cur > k) {
                    auto p = stack.back(); stack.pop_back();
                    ans = std::max(ans, p - i);
                    cur -= 1;
                } 
                cur -= 1;
                while (cur) {
                    auto p = stack.back(); stack.pop_back();
                    cur -= 1;
                }
            } else {
                stack.push_back(i);
                while (cur) {
                    auto p = stack.back(); stack.pop_back();
                    cur -= 1;
                }
            }


        }
        for (int i = 1; i <= 2 * n; ++i) {
            count[i] = 0;
        }
        std::cout << ans << '\n';
    }

    return 0;
}

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
ll n, k;
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        std::vector<ll> vec;
        int flag = 1;
        if (k > n) {
            flag = 0;
        } else {
            if (n > 2 * k - 2) {
                vec.push_back(n - k + 1);
                if (k - 1) vec.push_back(1);
            }
            else if (n == k) {
                vec.push_back(1);
            } else {
                flag = 0;
            }
        }
        if (flag) {
            std::cout << "YES\n" << vec.size() << '\n';
            for (auto it : vec) std::cout << it << ' ';
            std::cout << '\n';
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}

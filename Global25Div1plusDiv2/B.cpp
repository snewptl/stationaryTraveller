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
int n, k, a[maxn];
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }  
        std::vector<int> vec;
        for (int i = 1; i <= n; ++i) {
            if (a[i] > a[k]) vec.push_back(i);
        }
        int ans = 0;
        if (vec.size() == 0) {
            ans = n - 1;
        } else if (vec.size() == 1) {
            if (k < vec[0]) {
                ans = vec[0] - 2;
            } else {
                ans = std::max(vec[0] - 2, k - vec[0] - 1 + (vec[0] != 1));
            }
        } else {
            if (k < vec[0]) {
                ans = vec[0] - k - 1;
                if (k != 1) ans++; 
            } else if (k < vec[1]) {
                ans = k - vec[0] - 1;
                if (vec[0] != 1) ans++; 
            }
            else {
                ans = vec[1] - vec[0] - 1;
                if (vec[0] != 1) ans++; 
            }
            ans = std::max(ans, vec[0] - 2);
        }
        std::cout << ans << '\n';

    }

    return 0;
}

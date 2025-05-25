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
int n;
std::string s;
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> s;
        std::vector<int> vec;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '_') {
                if (!vec.empty()) {
                    ans += i - vec.back();
                    vec.pop_back();
                } else {
                    vec.push_back(i);
                }
            } else if (s[i] == '(') {
                vec.push_back(i);
            } else {
                ans += i - vec.back();
                vec.pop_back();
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}

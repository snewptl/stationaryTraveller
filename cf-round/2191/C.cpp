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
std::string s;
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
        std::cin >> n >> s;
        int count[2] = {0, 0};
        for (int i = 0; i < n; ++i) {
            count[s[i] - '0'] += 1;
        }
        if (count[0] == 0 || count[1] == 0) std::cout << "Bob\n";
        else {
            std::vector<int> vec;
            for (int i = 0; i < count[0]; ++i) {
                if (s[i] != '0') vec.push_back(i + 1);
            }
            for (int i = count[0]; i < n; ++i) {
                if (s[i] != '1') vec.push_back(i + 1);
            }
            if (vec.size() == 0) {
                std::cout << "Bob\n";
            } else {
                std::cout << "Alice\n";
                std::cout << vec.size() << '\n';
                for (auto it : vec) {
                    std::cout << it << ' ';
                }
                std::cout << '\n';
            }
        }
    }

    return 0;
}

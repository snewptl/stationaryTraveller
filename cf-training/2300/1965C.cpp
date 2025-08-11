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
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> s;
        std::vector<char> vec;
        for (int i = 0; i < n; ++i) {
            vec.push_back(s[i]);
            if (vec.size() % 2 == 0) {
                int flag = 1;
                for (int j = vec.size() / 2 - 1, k = vec.size() / 2; j >= 0, k < vec.size(); --j, ++k) {
                    if (vec[j] != vec[k]) flag = 0;
                }
                if (flag) vec.resize(vec.size() / 2);
            }
            if (vec.size() >= 3) {
                int flag = 1;
                char cur = vec.back();
                for (int i = vec.size() - 3; j < vec.size() - 1; ++j) {
                    if (cur != vec[i]) flag = 0;
                }
                if (flag) vec.resize(vec.size() - 2);
            }
            if (vec.size() >= 6) {
                int flag = 1;
                char l = vec[vec.size() - 6], r = vec[vec.size() - 5];
                if (l != vec[vec.size() - 3] || l != vec[vec.size() - 2]) flag = 0;
                if (r != vec[vec.size() - 4] || r != vec[vec.size() - 1]) flag = 0;
                if (flag) vec.resize(vec.size() - 4);
            }
        }
        int changed = 1;
        while (changed) {
            changed = 0;
            if (vec.size() >= 2) { 
                if (vec.back() == vec[vec.size() - 2]) {
                    vec.resize(vec.size() - 1);
                    changed = 1;
                }
            }
            if (vec.size() >= 4) {
                if (vec.back() == vec[vec.size() - 4] && vec[vec.size() - 2] == vec[vec.size() - 3]) {
                    vec.resize(vec.size() - 2);
                    changed = 1;
                }
            }
        }
        std::cout << vec.size() << '\n';
    }

    return 0;
}
// 9 : 55 - 11 : 15


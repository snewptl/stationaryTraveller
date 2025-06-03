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
std::string str;
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
        std::cin >> str;
        int n = str.size();
        int count = 0;
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            if (str[i] == '(') count += 1;
            else count -= 1;
            if (i < n - 1 && count == 0) flag = 1;
        }
        if (flag) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}
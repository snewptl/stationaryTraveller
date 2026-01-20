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
    while (T--){
        std::cin >> n >> s;
        int count[2] = {0, 0};
        int flag = 0;
        for (int i = n; i >= 1; --i) {
            if (s[i - 1] == '(') count[0] += 1;
            else {
                if (count[0] >= 2) flag = 1;
                count[1] += 1;
            }
        }
        if (flag) std::cout << n - 2 << '\n'; 
        else std::cout << "-1\n";
    }

    return 0;
}

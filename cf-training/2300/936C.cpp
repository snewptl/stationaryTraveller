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
std::string s, t;
std::vector<int> opt;
int dir;
void one_swap(int x) {
    x = n - x;
    opt.push_back(x);
    std::string temp = s;
    for (int i = 0; i < n - x; ++i) {
        temp[i + x] = s[i]; 
    }
    for (int i = 0; i < x; ++i) {
        temp[i] = s[n - 1 - i];
    }
    s = temp;
    // std::cout << x << ' ' << s << '\n';
}
bool solve() {
    for (int i = 0; i < n; ++i) {
        char ch;
        if (i % 2 == 0) {
            ch = t[(n - 1) / 2 - i / 2];
        } else {
            ch = t[(n - 1) / 2 + (i + 1) / 2];
        }
        int flag = 0;
        for (int j = i; j < n; ++j) {
            if (ch == s[j]) {
                flag = 1;
                one_swap(j + 1);
                one_swap(n - 1 - j + i);
                one_swap(n - i);
                break;
            }
        }
        if (!flag) return false;
    }
    if (n % 2) one_swap(0);
    std::cout << opt.size() << '\n';
    for (auto it : opt) {
        std::cout << it << ' ';
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
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> s >> t;
        if (!solve()) {
            std::cout << "-1\n";
        }
 
    }
 
    return 0;
}
// 8 : 45 - 
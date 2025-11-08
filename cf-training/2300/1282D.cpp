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
int ask(std::string& str) {
    std::cout << str << std::endl;
    int res;
    std::cin >> res;
    return res;
}
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    int len;
    s = "a";
    int len1 = ask(s);
    if (len1 >= 300) {
        s.clear();
        s.resize(len1, 'b');
        ask(s);
        exit(0);
    }
    s.resize(len1 + 1, 'a');
    int diff = ask(s);
    if (!diff) {
        exit(0);
    }
    if (len1 < diff) {
        s.clear();
        s.resize(len1, 'b');
        ask(s);
    } else {
        len = len1 + 1;
        for (int i = 0; i < len; ++i) {
            s[i] = 'b';
            int cur = ask(s);
            if (!cur) exit(0);
            if (cur < diff) {
                diff = cur;
            } else {
                s[i] = 'a';
            }
        } 
    }
    return 0;
}
// 13 : 31 - 
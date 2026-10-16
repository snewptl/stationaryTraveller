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
bool fin = 0;
int n, q;
int ask_count = 0;
bool ask(int l, int r) {
    ask_count += 1;
    assert(ask_count <= q);
    std::cout << "? " << l << ' ' << r << std::endl;
    std::string s;
    std::cin >> s;
    if (s[0] == 'Y') return true;
    else return false;
}
std::string ans;
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> q;
    std::vector<int> vec;
    vec.push_back(1);
    int l, r = 2;
    ans.resize(n);
    while (vec.size() < n - r + 1) {
        l = vec.back();
        if (!ask(l, r)) {
            vec.push_back(r);
            r += 1;
        } else {
            ans[l - 1] = '(';
            ans[r - 1] = ')';
            vec.pop_back();
            r += 1;
        }
        if (vec.empty()) {
            vec.push_back(r);
            r += 1;
        }
    }
    for (int i = r; i <= n; ++i) {
        ans[i - 1] = ')';
    }
    for (auto it : vec) {
        ans[it - 1] = '(';
    }
    std::cout << "! " << ans << std::endl;
    return 0;
}

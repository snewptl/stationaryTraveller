#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
std::string str[2];
int len[2];
std::vector<std::queue<int>> vec;
bool solve() {
    vec.clear();
    vec.resize(27);
    for (int i = 0; i < len[0]; ++i) {
        vec[str[0][i] - 'a'].push(i);
    }
    for (auto ch : str[1]) {
        int idx = ch - 'a';
        if (vec[idx].empty()) return false;
        int p = vec[idx].front(); vec[idx].pop();
        for (int i = 0; i < idx; ++i) {
            while (!vec[i].empty() && vec[i].front() < p) vec[i].pop();
        }
    }
    return true;
}
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
        std::cin >> len[0] >> len[1];
        std::cin >> str[0] >> str[1];
        if(solve()) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}

// 12 : 40 - 
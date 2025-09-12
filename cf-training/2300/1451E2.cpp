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
const int maxn = 1e5 + 5;
const ll mod = 998244353;

int n;
int col[17][maxn], a[maxn], xor_res[maxn];
int ask(int i, int j, std::string opt) {
    std::cout << opt << ' ' << i << ' ' << j << std::endl;
    int res;
    std::cin >> res;
    return res;
}
void output() {
    std::cout << "! ";
    for (int i = 1; i <= n; ++i) {
        std::cout << a[i] << ' ';
    } 
    std::cout << std::endl;
}
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i < n; ++i) {
        xor_res[i] = ask(i, i + 1, "XOR");
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 0; j < 16; ++j) {
            if ((1 << j) & xor_res[i]) {
                col[j][i] = col[j][i + 1] ^ 1;
            } else {
                col[j][i] = col[j][i + 1];
            }
        }
    }
    std::vector<int> vec;
    for (int i = 1; i <= n; ++i) {
        vec.push_back(i);
    }
    for (int j = 15; j >= 1; --j) {
        std::vector<int> temp[2];
        for (auto it : vec) {
            temp[col[j][it]].push_back(it);
        }
        if (temp[0].size() < temp[1].size()) std::swap(temp[0], temp[1]);
        vec = temp[0];
    }
    assert(vec.size() >= 2);
    int top_bit = ask(vec[0], vec[1], "AND");
    for (int j = 15; j >= 1; --j) {
        for (int i = 1; i <= n; ++i) {
            if (col[j][i] == col[j][vec[0]]) {
                if (top_bit & (1 << j)) {
                    a[i] += 1 << j;
                }
            } else {
                if (!(top_bit & (1 << j))) {
                    a[i] += 1 << j;
                }
            }
        }
    }
    std::vector<int> temp[2];
    for (int i = 1; i <= n; ++i) {
        temp[col[0][i]].push_back(i);
    }
    if (temp[0].size() < temp[1].size()) std::swap(temp[0], temp[1]);
    vec = temp[0];
    assert(vec.size() >= 2);
    int low_bit = ask(vec[0], vec[1], "AND");
    for (int i = 1; i <= n; ++i) {
        if (col[0][i] == col[0][vec[0]]) {
            if (low_bit & 1) {
                a[i] += 1;
            }
        } else {
            if (!(low_bit & 1)) {
                a[i] += 1;
            }
        }
    }
    output();
    return 0;
}
// 10 : 42 - 12 : 03
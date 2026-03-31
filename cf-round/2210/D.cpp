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
const int maxn = 5e5 + 5;
const ll mod = 998244353;
int n;
std::string s, t;
int count[2][3];
int last[2][maxn];
bool check() {
    for (int i = 0; i < 3; ++i) {
        if (count[0][i] != count[1][i]) return false;
    }
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
    std::cin >> T;
    while (T--) {
        std::cin >> n >> s >> t;
        count[0][0] = count[0][1] = count[1][0] = count[1][1] = 0;
        count[0][2] = count[1][2] = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') count[0][0] += 1;
                else count[0][1] += 1; 
            }
        }
        for (int i = 0; i < n; ++i) {
            if (t[i] == ')') {
                if (t[i - 1] == '(') count[1][0] += 1;
                else count[1][1] += 1; 
            }
        }
        std::vector<int> vec;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' ) vec.push_back(i);
            else {
                last[0][i] = vec.back();
                vec.pop_back();
            }
        }
        for (int i = n - 1; i >= n / 2; --i) {
            if (s[i] == '(') break;
            if (last[0][i] == n - 1 - i) count[0][2] += 1;
            else break;
        }
        vec.clear();
        for (int i = 0; i < n; ++i) {
            if (t[i] == '(' ) vec.push_back(i);
            else {
                last[1][i] = vec.back();
                vec.pop_back();
            }
        }
        for (int i = n - 1; i >= n / 2; --i) {
            if (t[i] == '(') break;
            if (last[1][i] == n - 1 - i) count[1][2] += 1;
            else break;
        }
        if (check()) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}

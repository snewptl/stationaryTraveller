#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n;
std::string s;
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> s;
        int tot = 0, flag = 1, isAdjacent = 0;
        int last = '0';
        for (auto it : s) {
            if (it == '1'){
                tot++;
                if (last == '1') isAdjacent = 1;
            }
            last = it;
        }
        if (tot % 2) flag = 0;
        else {
            if (tot == 2 && isAdjacent) flag = 0; 
        }
        if (!flag)
            std::cout << "NO" << '\n';
        else
            std::cout << "YES" << '\n';
    }

    return 0;
}

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
std::string s1, s2, s3;
int fa[maxn];
int find(int x) {
    return fa[x] == x ? x : x = find(fa[x]);
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
        std::cin >> s1 >> s2 >> s3;
        for (int i = 0; i < 26; ++i) fa[i] = i;
        int len = s1.size();
        if (len != s2.size()) std::cout << "NO\n";
        else {
            if (s3.size() != len) std::cout << "YES\n"; 
            else {
                int flag = 0;
                for (int i = 0; i < len; ++i) fa[find(s2[i] - 'a')] = find(s1[i] - 'a');
                for (int i = 0; i < len; ++i) {
                    if (find(s3[i] - 'a') != find(s1[i] - 'a')) flag = 1; 
                }
                std::cout << (flag ? "YES\n" : "NO\n");
            }

        }
    }

    return 0;
}

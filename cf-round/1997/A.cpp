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
std::string s;
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) { 
        std::cin >> s;
        int flag = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i && !flag && s[i] == s[i - 1]){
                std::cout << (char)((s[i] - 'a' + 1) % 26 + 'a');
                flag = 1;
            }
            std::cout << s[i];
        }
        if (!flag) std::cout << (char)((s[s.size() - 1] - 'a' + 1) % 26 + 'a');
        std::cout << '\n';
        
    }

    return 0;
}

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
int n, a[maxn];
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
        std::cin >> n;
        int odd = 0, five = 0;
        for (int i = 1; i <= n; ++i) {
            int x;
            std::cin >> x;
            if (x == 1) ++odd;
            else if (x >= 5 && x % 2 == 1) ++five;
        }
        if (five) std::cout << "Bob\n";
        else if(odd % 2) std::cout << "Alice\n";
        else std::cout << "Bob\n";
    }

    return 0;
}

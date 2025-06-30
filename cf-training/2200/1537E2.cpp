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
const int maxn = 5e5 + 5;
const ll mod = 998244353;
int n, K;
std::string s;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> K >> s;
    int i = 1;
    while (i < n) {
        int j = i;
        int smaller = 0, bigger = 0;
        int t = 0;
        while (j < n && t < i) {
            if (s[t] != s[j]) {
                if (s[t] < s[j]) bigger = 1;
                else smaller = 1;
                ++j;
                break;
            } else {
                ++j;
                ++t;
            }

        }
        if (smaller) {
            i = j;
        } else if (bigger) {
            break;
        } else {
            if (j - i >= i) i = j;
            else break; 
        }
    }

    for (int j = 0; j < K; ++j) {
        std::cout << s[j % i];
    }
    std::cout << '\n';

    return 0;
}

// 11 : 30 - 10 : 
// 

/*
edceedce

s t s t s t

s s s s s s 

edcedc

*/
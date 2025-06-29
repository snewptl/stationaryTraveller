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
    int flag = 1, head = 1, end = 1;
    int i = 1;
    while (i < n && s[i] < s[0]) ++i, ++head, ++end;
    while (i < n) {
        if (s[i] > s[0]) break; 
        if (s[i] < s[0]) {
            assert(false);
        }  else { // =
            assert(s[i] == s[0]);
            int j = i + 1;
            while (j < n && s[j] < s[0]) ++j;
            int smaller = 0, bigger = 0;
            for (int k = i + 1, t = 1; k < j, t < head; ++k, ++ t) {
                if (s[k] < s[t]) {
                    smaller = 1;
                    break;
                } else if (s[k] > s[t]) {
                    bigger = 1;
                    break;
                }
            }
            if (!bigger && (smaller || j - i >= head)) {
                end = j;
            } else {
                break;
            }
            i = j;
        }
    }

    for (int i = 0; i < K; ++i) {
        std::cout << s[i % end];
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
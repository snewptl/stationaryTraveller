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
std::set<pii> spell[2];
std::multiset<int> in;
std::multiset<int, std::greater<int>> out;
int n;
ll sum[2], largest;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        int tp, d;
        std::cin >> tp >> d;
        if (d < 0) {
            d = -d;
            auto spell_ptr = spell[tp].lower_bound({d, 0});
            assert(spell_ptr != spell[tp].end() && spell_ptr->first == d);
            auto new_spell = std::make_pair(d, spell_ptr->second - 1);
            spell[tp].erase(spell_ptr);
            if (new_spell.second) spell[tp].insert(new_spell);
            sum[tp] -= d; 
            auto out_ptr = out.lower_bound(d);
            if (*out_ptr == d) {
                out.erase(out_ptr);
            } else {
                auto in_ptr = in.lower_bound(d);
                assert(in_ptr != in.end());
                assert(*in_ptr == d);
                in.erase(in_ptr);
                largest -= d;
                if (!out.empty()) {
                    out_ptr = out.begin();
                    in.insert(*out_ptr);
                    largest += *out_ptr;
                    out.erase(out_ptr);
                }
            }
        } else {
            auto spell_ptr = spell[tp].lower_bound({d, 0});
            if (spell_ptr == spell[tp].end() || spell_ptr->first != d) {
                spell[tp].insert({d, 1});
            } else {
                spell[tp].insert({d, spell_ptr->second + 1});
                spell[tp].erase(spell_ptr);
            }
            sum[tp] += d;
            if (!out.empty()) {
                auto out_ptr = out.begin();
                largest += *out_ptr;
                in.insert(*out_ptr);
                out.erase(out_ptr);
            }            
            in.insert(d);
            largest += d;
        }
        while (in.size() > spell[1].size()) {
            auto in_ptr = in.begin();
            largest -= *in_ptr;
            out.insert(*in_ptr);
            in.erase(in_ptr);
        }
        ll res = sum[0] + sum[1] + largest;
        if (!spell[1].empty() && (out.empty() || spell[1].begin()->first > *out.begin())) {
            res -= *in.begin();
            if (!out.empty()) {
                res += *out.begin();
            }
        }
        std::cout << res << '\n';
    }

    return 0;
}
// 14 : 09 - 15 : 04
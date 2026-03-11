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
using namespace std;
#define int long long
 
void solve() {
	int n, h; cin >> n >> h;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	vector<int> cnt(n);
	for (int i = 0; i < n; i++) {
		int curr = v[i];
		cnt[i] = h - curr;
		for (int j = i+1; j < n; j++)
			curr = max(curr, v[j]), cnt[i] += h - curr;
		curr = v[i];
		for (int j = i-1; j >= 0; j--)
			curr = max(curr, v[j]), cnt[i] += h - curr;
	}
	
	//~ for (int i = 0; i < n; i++)
		//~ cout << v[i] << "\n";
	
	int best = 0;
	for (int i = 0; i < n; i++) {
		int mx = v[i], arg = i;
		for (int j = i; j < n; j++) {
			if (v[j] > mx) {
				mx = v[j];
				arg = j;
			}
			best = max(cnt[i] + cnt[j] - cnt[arg], best);
		}
	}
	cout << best << "\n";
}
 
 
signed main() {
    freopen("0_input.txt", "r", stdin);
    freopen("stdOut.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}
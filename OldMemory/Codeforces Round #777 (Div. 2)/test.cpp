#include <bits/stdc++.h>
 
using namespace std;
 
const int inf = 1e9 + 228;
 
int solve (int n, vector<int> a) {
    int ind = max_element(a.begin(), a.end()) - a.begin();
    vector<int> dp1(n, inf);
    dp1[0] = -1;
    for (int i = 1; i <= ind; ++i) {
        if (a[i] > dp1[i - 1])
            dp1[i] = min(dp1[i], a[i - 1]);
        if (a[i] > a[i - 1])
            dp1[i] = min(dp1[i], dp1[i - 1]);
    }
 
    vector<int> dp2(n, inf);
    dp2[n - 1] = -1;
    for (int i = n - 2; i >= ind; --i) {
        if (a[i] > dp2[i + 1])
            dp2[i] = min(dp2[i], a[i + 1]);
        if (a[i] > a[i + 1])
            dp2[i] = min(dp2[i], dp2[i + 1]);
    }
 
    vector<array<int, 2>> dp3(n, {inf, -inf});
    dp3[ind][0] = dp1[ind];
    int ans = 0;
    for (int i = ind + 1; i < n; ++i) {
        if (a[i - 1] > a[i])
            dp3[i][0] = min(dp3[i][0], dp3[i - 1][0]);
        if (dp3[i - 1][1] > a[i])
            dp3[i][0] = min(dp3[i][0], a[i - 1]);
        
        if (a[i - 1] < a[i])
            dp3[i][1] = max(dp3[i][1], dp3[i - 1][1]);
        if (dp3[i - 1][0] < a[i])
            dp3[i][1] = max(dp3[i][1], a[i - 1]);
        
        if (dp3[i][1] > dp2[i])
            ++ans;
    }
    return ans;
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = solve(n, a);
    reverse(a.begin(), a.end());
    cout << ans + solve(n, a) << '\n';
}
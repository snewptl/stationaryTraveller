#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxn=2e5+5;
const double eps=1e-10;
int q;
vector<int>vec, ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin >> q;
        vec.clear();
        ans.clear();
        int flag = 0;
        while(q--) {
            int x;
            cin >> x;
            if(!flag) {
                if(!vec.empty() && x < vec.back()) {
                    if(x <= vec[0]) {
                        flag = 1;
                        ans.push_back(1);
                        vec.push_back(x);
                    }
                    else ans.push_back(0);
                }
                else {
                    ans.push_back(1);
                    vec.push_back(x);                    
                }
            }
            else if(x <= vec[0] && x >= vec.back()) {
                vec.push_back(x);
                ans.push_back(1);
            }
            else ans.push_back(0);
        }
        for(auto it: ans) {
            cout << it;
        }
        cout << '\n';
    }

    return 0;
}
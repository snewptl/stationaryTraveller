#include<bits/stdc++.h>
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
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        if(n%2==0)cout<<"-1\n";
        else {
            vector<int>vec;
            while(n>1){
                n/=2;
                if(n%2==1)vec.push_back(2);
                else {
                    n++;
                    vec.push_back(1);
                }
            }
            cout<<vec.size()<<'\n';
            reverse(vec.begin(),vec.end());
            for(auto it:vec)cout<<it<<" ";
            cout<<'\n';
        }
    }

    return 0;
}
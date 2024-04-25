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
int n,s1,s2;
int r[maxn];
set<pii,greater<pii>>s;
vector<int>vec1,vec2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>s1>>s2;
        s.clear();
        vec1.clear();
        vec2.clear();
        for(int i=1;i<=n;i++)cin>>r[i];
        for(int i=1;i<=n;i++){
            s.insert({r[i],i});
        }
        int cnt1=1,cnt2=1;
        while(!s.empty()){
            auto it=s.begin();
            if(cnt1*s1<=cnt2*s2){
                vec1.push_back(it->second);
                cnt1++;
            }
            else {
                vec2.push_back(it->second);
                cnt2++;
            }
            s.erase(it);
        }
        cout<<vec1.size()<<" ";
        for(auto it:vec1)cout<<it<<" ";
        cout<<'\n';
        cout<<vec2.size()<<" ";
        for(auto it:vec2)cout<<it<<" ";
        cout<<'\n';
    }

    return 0;
}
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
string sa,sb;
vector<int>vec[2],ans;
int fst(int sgn){
    for(int i=0;i<n;i++)if(vec[sgn][i])return i;
    return -1;
}
int lst(int sgn){
    for(int i=n-1;i>=0;i--)if(vec[sgn][i])return i;
    return -1;
}
void init(){
    vec[0].clear();vec[1].clear();
    ans.clear();
    for(auto it:sa)vec[0].push_back(it-'0');
    for(auto it:sb)vec[1].push_back(it-'0');    
}
void movle(int x){
    for(int i=0;i<n&&i+x<n;i++)
        vec[0][i]^=vec[0][i+x];    
    // for(int i=0;i<n;i++)cout<<vec[0][i];
    // cout<<'\n';
}
void movri(int x){
    for(int i=n-1;i>=0&&i-x>=0;i--)
        vec[0][i]^=vec[0][i-x];        
    // for(int i=0;i<n;i++)cout<<vec[0][i];
    // cout<<'\n';
}
void solve(){
    // if(fst(0)>fst(1)){
    //     int cur=fst(0)-fst(1);
    //     ans.push_back(cur);
    //     movle(cur);
    // }
    if(fst(0)>lst(1)){
        for(int i=lst(0)-1;i>=0;i--){
            if(vec[0][i]!=vec[1][i]){
                int x=lst(0);
                movle(x-i);
                ans.push_back(x-i);
            }            
        }
        for(int i=lst(0);i<n;i++){
            if(vec[0][i]!=vec[1][i]){
                int x=fst(0);
                movri(i-x);
                ans.push_back(x-i);
            }
        }
    }
    else {
        for(int i=fst(0)+1;i<n;i++){
            if(vec[0][i]!=vec[1][i]){
                int x=fst(0);
                movri(i-x);
                ans.push_back(x-i);
            }
        }
        for(int i=fst(0);i>=0;i--){
            if(vec[0][i]!=vec[1][i]){
                int x=lst(0);
                movle(x-i);
                ans.push_back(x-i);
            }
        }        
    }

}
bool zr(string &x){
    for(auto it:x){
        if(it!='0')return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>sa>>sb;
        if(zr(sa)||zr(sb)){
            if(!zr(sa)||!zr(sb))
                cout<<"-1"<<'\n';     
            else cout<<"0"<<'\n';
            continue;                
        }
        init();
        solve();
        assert(ans.size()<=n);
        cout<<ans.size()<<'\n';
        for(auto it:ans)cout<<it<<' ';
        if(ans.size())cout<<'\n';
    }

    return 0;
}
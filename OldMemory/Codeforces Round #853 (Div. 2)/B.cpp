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
string s;
bool solve(){
    int flag=0;
    for(int i=0;i<s.size()/2;i++){
        int x=i,y=s.size()-i-1;
        if(!flag){
            if(s[x]!=s[y]){
                flag=1;
            }
        }
        else if(flag==1){
            if(s[x]==s[y]){
                flag=2;
            }
        }
        else {
            if(s[x]!=s[y])return false;
        }
    }    
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>s;
        if(solve())cout<<"Yes";
        else cout<<"No";
        cout<<'\n';

    }

    return 0;
}
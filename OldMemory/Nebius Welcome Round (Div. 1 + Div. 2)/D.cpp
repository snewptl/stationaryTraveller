#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxn=5e5+5;
const double eps=1e-10;
int n,m;
string vec[maxn];
int solvemn(){
    int ans=0;
    for(int i=1;i<=n;i++){
        int lst=-1,on=m/2,tw=m/4;
        for(int j=0;j<m;j++){
            int cur=vec[i][j]-'0';
            // cout<<j<<" "<<lst<<" "<<cur<<'\n';
            if(lst==-1)lst=cur;
            else {
                if(tw&&((lst&cur)||(!on))){
                    tw--,ans+=(lst|cur),lst=-1;
                }
                else {
                    ans+=lst;
                    lst=cur;
                    on--;
                }
            }
        }
        if(lst!=-1)ans+=lst,on--;
        assert(on==0&&tw==0);
    }
    return ans;
}
int solvemx(){
    int ans=0;
    for(int i=1;i<=n;i++){
        int lst=-1,on=m/2,tw=m/4;
        for(int j=0;j<m;j++){
            int cur=vec[i][j]-'0';
            if(lst==-1)lst=cur;
            else {
                if(tw&&((!(lst&cur))||!on))tw--,ans+=(lst|cur),lst=-1;    
                else {
                    ans+=lst;
                    lst=cur;
                    on--;
                }
            }
        }
        if(lst!=-1)ans+=lst,on--;
        assert(on==0&&tw==0);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            string str;
            cin>>str;
            vec[i]=str;
        }
    }
    
    cout<<solvemn()<<" "<<solvemx()<<'\n';

    return 0;
}
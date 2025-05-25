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
const int inf=1e9;
const double eps=1e-10;
int n,k;
int x[25],c[25];
char nxt[maxn];
string res;
void solve(){
    res="abc";
    char cur='d';
    char back='a';
    for(int i=1;i<=k;i++){
        if(x[i]<=3){
            if(c[i]!=x[i]){
                cout<<"NO\n";
                return;
            }
        }
        else {
            if(x[i-1]<3){
                x[i-1]=c[i-1]=3;
            }
            if(x[i]-x[i-1]+c[i-1]<c[i]){
                cout<<"NO\n";
                return ;
            }
            else {
                for(int j=1;j<=c[i]-c[i-1];j++)res+=cur;
                cur++;
                for(int j=c[i]-c[i-1]+1;j<=x[i]-x[i-1];j++){
                    res+=back;
                    back=nxt[back];
                }
            }
        }
    }
    for(int i=res.size()+1;i<=n;i++){
        res+=back;
        back=nxt[back];        
    }
    cout<<"YES\n"<<res<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;cin>>T;
    nxt['a']='b';
    nxt['b']='c';
    nxt['c']='a';
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=k;i++)cin>>x[i];
        for(int i=1;i<=k;i++)cin>>c[i];
        solve();
    }

    return 0;
}
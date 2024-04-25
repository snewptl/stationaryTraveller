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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));
    int T=rand()%20+1;cout<<T<<'\n';
    for(int i=1;i<=T;i++){
        for(int j=0;j<rand()%20+1;j++){
            cout<<rand()%2;
        }
        cout<<'\n';
    }

    return 0;
}
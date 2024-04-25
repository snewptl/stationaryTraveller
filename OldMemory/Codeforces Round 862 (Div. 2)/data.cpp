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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));
    cout<<"1\n";
    int n=rand()+1;
    cout<<"1 "<<n<<'\n';
    cout<<rand()-rand()<<'\n';
    for(int i=1;i<=n;i++){
        cout<<rand()<<' '<<rand()-rand()<<' '
            <<rand()-rand()<<'\n';
    }

    return 0;
}
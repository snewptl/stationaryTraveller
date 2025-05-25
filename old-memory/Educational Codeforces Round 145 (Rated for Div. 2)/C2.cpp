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
vector<int>vec,ans;
int n,k,flag;
void init(int n){
    vec.clear();
    for(int i=n;i>=1;i--){
        int temp=i*(i+1)/2;
        while(temp<=k){
            k-=temp;
            vec.push_back(i);
        }
    }
}
int solve0(){
    ans.clear();
    ans.resize(n);
    for(auto &it:ans)it=-31;
    for(int i=n-1;i>=0;i--){
        if(k>=i+1)ans[i]=1000,k-=i+1;
        else return i+1;
    }
    return 0;
}
void solve1(int m){
    if(k==0)return ;
    ans[k-1]=30;
    for(int i=0;i<k-1;i++)ans[i]=-1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>k;
        solve1(solve0());
        assert(ans.size()==n);
        for(auto it:ans)cout<<it<<' ';
        cout<<'\n';
    }

    return 0;
}
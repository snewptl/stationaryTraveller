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
void init(int x){
    vec.clear();
    flag=0;
    if(x>(n+1)*n/2/2)flag=1,x=n*(n+1)/2-x;
    for(int i=n;i>=1;i--){
        int temp=i*(i+1)/2;
        while(temp<=x){
            x-=temp;
            vec.push_back(i);
        }
    }
}
void solve0(){
    ans.clear();
    for(int i=0;i<n;i++){
        ans.push_back(-(1<<i));
    }
    for(int i=n-1;i>=0;i--){
        if(k>=i+1)ans[i]*=-1,k-=(i+1);
    }
}
void solve1(){
    ans.clear();
    for(auto it:vec){
        for(int i=1;i<=it;i++)ans.push_back(1);
        if(ans.size()<n)ans.push_back(-1000);
    }
    while(ans.size()<n)ans.push_back(-1000);
    assert(ans.size()==n);
    if(flag)for(auto &it:ans)it=-it;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>k;
        init(k);
        if(n<=9)solve0();
        else solve1();
        for(auto it:ans)cout<<it<<' ';
        cout<<'\n';
    }

    return 0;
}
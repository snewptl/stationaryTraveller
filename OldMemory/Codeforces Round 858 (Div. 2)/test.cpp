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
int a[5],res=1e9;
int b[5]={0,-2,-2,2,2};
void dfs(int dep){
    if(dep==5){
        int temp=0;
        if(a[1]+a[4]==a[2]*a[3]&&a[1]+a[3]==a[2]*a[4]
        &&a[1]+a[2]==a[4]*a[3]&&a[2]+a[3]==a[1]*a[4]&&
        a[2]+a[4]==a[1]*a[3]&&a[3]+a[4]==a[1]*a[2]){
            for(int i=1;i<=4;i++)temp+=abs(b[i]-a[i]);
            if(temp==5){
                for(int i=1;i<=4;i++)cout<<a[i]<<' ';
                cout<<'\n';
            }
        }
        return;
    }
    for(int i=-5;i<=5;i++){
        a[dep]=i;
        dfs(dep+1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    dfs(1);

    return 0;
}
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
string vec[maxn];
int n=1,m=8;
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
int find(int x,int y){
    if(x==4&&y==2){
        return 0;
    }
    int ans=8;
    if(x<4)ans=min(ans,vec[1][x+y*2]-'0'+find(x+1,y));
    if(y<2)ans=min(ans,(((vec[1][x+y*2]-'0')|(vec[1][x+y*2+1]-'0'))+find(x,y+1)));
    return ans;
}
int baoli(){
    return find(0,0);
}
void dfs(int dep){
    if(dep==8){
        if(baoli()!=solvemn())cout<<vec[1]<<" "<<baoli()<<" "<<solvemn()<<'\n';
        return;
    }
    vec[1].push_back('1');
    dfs(dep+1);
    vec[1].pop_back();
    vec[1].push_back('0');
    dfs(dep+1);
    vec[1].pop_back();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    dfs(0);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=3e3+5;
const ll mod=998244353;
const double eps=1e-10;
int fa[2][maxn];
int find(int x,int sgn){
    return fa[sgn][x]==x?x:fa[sgn][x]=find(fa[sgn][x],sgn);
}
int n,a[maxn],b[maxn];
set<int>s[2][maxn];
int rk[2][maxn],vis[maxn];
vector<int>ans;
void init(int *a,int sgn){
    for(int i=1;i<=n;i++)rk[sgn][a[i]]=i;
    for(int i=1;i<=n;i++)fa[sgn][i]=i;
    for(int i=1;i<=n;i++)fa[sgn][find(i,sgn)]=find(rk[sgn][i],sgn);
    for(int i=1;i<=n;i++)s[sgn][find(i,sgn)].insert(i);
}
void solve(){
    for(int i=1;i<=n;i++){
        if(s[0][find(i,0)].size()>1&&s[1][find(i,1)].size()>1){
            ans.push_back(i);
            s[0][find(i,0)].erase(i);
            s[1][find(i,1)].erase(i);
            vis[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        assert(!(s[0][find(i,0)].size()>1&&s[1][find(i,1)].size()>1));
        if(s[0][find(i,0)].size()>1){
            ans.push_back(i);
            s[0][find(i,0)].erase(i);
        }
        if(s[1][find(i,1)].size()>1){
            ans.push_back(i);
            s[1][find(i,1)].erase(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    init(a,0);init(b,1);
    solve();
    cout<<ans.size()<<'\n';
    for(auto it:ans)cout<<it<<' ';
	return 0;
}

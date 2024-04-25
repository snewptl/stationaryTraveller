#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=3e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[maxn];
int dp[maxn][2][2],f[maxn][2][2];
void update(vector<pii>vec,int dep){
    if(dep<0)return;
    int sz=1<<dep;
    int pre[2]={0,0},nxt[2]={0,0};
    vector<pii>le,ri;
    for(auto it:vec){
        if((it.second&sz)==0){
            if((it.first&sz)==0)le.push_back(it);
            else ri.push_back(it);

            for(int j=0;j<2;j++){
                pre[j]=max(pre[j],f[it.second][1][j]);
            }
        }
        else {
            if((it.first&sz)==1)le.push_back(it);
            else ri.push_back(it);
            for(int j=0;j<2;j++){
                nxt[j]=max(nxt[j],f[it.second][0][j]);
            }
        }
    }
    for(auto it:vec){
        if((it.first&sz==0))continue;
        if((it.second&sz)==0)dp[it.second][0]=max(dp[it.second][0],nxt+f[it.second][0]);
        else dp[it.second][1]=max(dp[it.second][1],pre+f[it.second][1]);
    }
    update(le,dep-1);
    update(ri,dep-1);    
}
void solve(int l,int r,int dep){
    int sz=1<<dep;
    if(!dep)return;
    vector<pii>vec;
    for(int i=l;i<=r;i++)vec.push_back({a[i],i});
    solve(l,min(r,l+sz-1),dep-1);
    if(l+sz<=r)solve(l+sz,r,dep-1);
    int pre={0,0},nxt={}
    for(int i=l;i<=r;i++){
        dp[i][]
    }
    for(int i=l;i<=r;i++){
        for(int t=0;t<2;t++)
        for(int j=0;j<2;j++)
        f[i][t][j]=dp[i][t][j];
    }
    update(vec,dep);
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<n;i++){
            if(a[i]&1)
                for(int j=0;j<2;j++)
                    dp[i][j][1]=1;
            else 
                for(int j=0;j<2;j++)
                    dp[i][j][0]=1;
        }
        solve(0,n-1,20);
	}
	return 0;
}
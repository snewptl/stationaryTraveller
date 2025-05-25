#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lc nd<<1
#define rc nd<<1|1
#define lowbit(x) (x&(-x))
#define pLL pair<LL,LL>

using namespace std;

const int mn=306;
int n,m,a[mn],b[mn],ans[mn];
string s[mn],fr[mn],ed[mn];
map<string,int> vis[mn];

void solve(int k)
{
    for(int i=1;i<=n+m;++i) vis[i].clear();
    for(int i=1;i<=n;++i) {
        for(int j=0;j<int(s[i].size())-k;++j) {
            vis[i][s[i].substr(j,k)]=1;
        }
    }
    for(int i=1;i<=m;++i) {
        int u=a[i],v=b[i];
        for(auto it:vis[u]) vis[n+i][it.fi]=1;
        for(auto it:vis[v]) vis[n+i][it.fi]=1;
        string tmp=ed[u]+fr[v];
        for(int j=0;j<ed[u].size();++j) {
            int pos=j+k-1;
            if(pos>=tmp.size()) break;
            vis[n+i][tmp.substr(j,k)]=1;
        }
        if(vis[n+i].size()==(1ll<<k)) ans[i]=max(ans[i],k);
        if(fr[u].size()<30) {
            fr[i+n]=tmp.substr(0,min(30,int(tmp.size())));
        }
        else {
            fr[i+n]=fr[u];
        }
        if(ed[v].size()<30) {
            ed[i+n]=tmp.substr(tmp.size()-min(30,(int)tmp.size()));
        }
        else {
            ed[i+n]=ed[v];
        }
    }
}

int main()
{
    int tests=1;//scanf("%d",&tests);
    while(tests--) {
        scanf("%d",&n);
        for(int i=1;i<=n;++i) {
            cin>>s[i];
        }
        for(int i=1;i<=n;++i) for(int j=0;j<min(int(s[i].size()),30);++j) fr[i]+=s[i][j];
        for(int i=1;i<=n;++i) 
            for(int j=s[i].size()-min(int(s[i].size()),30);j<int(s[i].size());++j) ed[i]+=s[i][j];
        scanf("%d",&m);
        for(int i=1;i<=m;++i) {
            scanf("%d%d",a+i,b+i);
        }
        for(int i=1;i<=30;++i) solve(i);
        for(int i=1;i<=m;++i) printf("%d\n",ans[i]);
    }
    return 0;
}
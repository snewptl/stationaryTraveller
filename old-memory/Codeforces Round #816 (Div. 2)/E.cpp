#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,k;
ll ans[maxn];
vector<pii>e[maxn];
priority_queue<pii,vector<pii>,greater<pii> >q;
ll dis[maxn];
int vis[maxn],in[maxn];
void dij(){
    memset(vis,0,sizeof(vis));
    memset(in,0,sizeof(in));
    q.push({0,1});
    dis[1]=0;
    while(!q.empty()){
        auto p=q.top();q.pop();
        ll val=p.first;
        int u=p.second;
        in[u]=0;
        if(vis[u])continue;
        vis[u]=1;
        for(auto it:e[u]){
            int v=it.first,w=it.second;
            if(val+w<dis[v]||(val+w==dis[v]&&!in[v])){
                dis[v]=val+w;
                in[v]=1;
                q.push({dis[v],v});
            }
        }
    }
}
vector<pll>line,pt;
bool cmp_left(pll x, pll y){
    // return x.first*y.second<y.first*x.second;
    return 1.0*x.first/x.second<=1.0*y.first/y.second;
}
bool cmp_right(pll x,pll y){
    // return x.first*y.second>y.first*x.second;
    return 1.0*x.first/x.second>=1.0*y.first/y.second;
}

pll get_point(pll cur){
    pll pre=line.back();
    ll up=pre.second-cur.second;
    ll dn=cur.first-pre.first;
    if(dn<0)up*=-1,dn*=-1;
    return {up,dn};
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    memset(dis,0x3f,sizeof(dis));
    dij();
    for(int t=1;t<=k;t++){
        line.clear();
        pt.clear();
        for(int i=1;i<=n;i++){
            if(dis[i]<=1e15){
                pll cur_line={-2ll*i,1ll*i*i+dis[i]};
                if(line.empty()){
                    pt.push_back({-1e9,1});
                    line.push_back(cur_line);
                }    
                else {
                    pll nxt=get_point(cur_line);
                    while(!line.empty()&&cmp_left(nxt,pt.back())){
                        line.pop_back(),pt.pop_back();
                        if(!line.empty())nxt=get_point(cur_line);
                    }
                    line.push_back(cur_line);
                    pt.push_back(nxt);
                    // printf("%lld %lld %lld\n",cur_line.first,nxt.first,nxt.second);
                }                
            }
            // auto it=upper_bound(pt.begin(),pt.end(),make_pair(i,1),cmp_left)-pt.begin()-1;
            // assert(it<0);
            if(line.empty())continue;
            int res=0,l=0,r=pt.size()-1;
            while(l<=r){
                int mid=l+r>>1;
                if(cmp_left({i,1},pt[mid]))r=mid-1;
                else l=mid+1,res=max(res,mid);
            }
            ans[i]=min(dis[i],line[res].first*i+line[res].second+1ll*i*i);
        }
        line.clear();
        pt.clear();
        for(int i=n;i>=1;i--){
            if(dis[i]<=1e15){
                pll cur_line={-2*i,1ll*i*i+dis[i]};
                if(line.empty()){
                    pt.push_back({1e9,1});
                    line.push_back(cur_line);
                }    
                else {
                    pll nxt=get_point(cur_line);
                    while(!line.empty()&&cmp_right(nxt,pt.back())){
                        line.pop_back(),pt.pop_back();
                        if(!line.empty())nxt=get_point(cur_line);
                    }
                    line.push_back(cur_line);
                    pt.push_back(nxt);
                }                
            }
            // auto it=upper_bound(pt.begin(),pt.end(),make_pair(i,1),cmp_right)-pt.begin()-1;
            // assert(it<0);
            if(line.empty())continue;
            int res=0,l=0,r=pt.size()-1;
            while(l<=r){
                int mid=l+r>>1;
                if(cmp_right({i,1},pt[mid]))r=mid-1;
                else l=mid+1,res=max(res,mid);
            }
            ans[i]=min(ans[i],min(dis[i],line[res].first*i+line[res].second+1ll*i*i));
        
        }
        for(int i=1;i<=n;i++)
            dis[i]=ans[i];
        dij();
    }
    for(int i=1;i<=n;i++){
        printf("%lld ",dis[i]);
    }

	return 0;
}
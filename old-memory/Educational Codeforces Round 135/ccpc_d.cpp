#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int>pli;
typedef pair<int,int>pii;
const int maxn=1e5+5;
const ll inf=1e18;
int n;
vector<pii>e[maxn];
ll ze[maxn],se[maxn],tw[maxn],on[maxn];
pli fi[maxn][2];
ll sum[maxn];
ll ans;
void init(){
    for(int i=1;i<=n;i++){
        e[i].clear();
        sum[i]=0;
        se[i]=tw[i]=on[i]=0;
        fi[i][0]={0ll,0};
        fi[i][1]={0ll,0};
    }
}
void dfs1(int u,int p){

    for(auto it:e[u]){
        int v=it.first,w=it.second;
        if(v==p)continue;
        dfs1(v,u);
        sum[u]+=sum[v]+w;

        tw[v]=se[v];
        if(w==0)tw[v]+=2;
        else tw[v]+=w%2;
        se[u]+=min(tw[v],sum[v]+w);
        
        on[v]=fi[v][0].first;
        if(w==0)on[v]++;
        else on[v]+=(w%2)^1;
    }
    for(auto it:e[u]){
        int v=it.first,w=it.second;
        if(v==p)continue;
        ll cur=se[u]-min(tw[v],sum[v]+w)+on[v];
        if(!fi[u][0].second)
            fi[u][0]={cur,v};
        else {
            if(fi[u][0].first>cur){
                fi[u][1]=fi[u][0];
                fi[u][0]={cur,v};
            }
            else {
                if(!fi[u][1].second)
                    fi[u][1]={cur,v};
                else if(fi[u][1].first>cur)
                    fi[u][1]={cur,v};
            }
        }
    }
    printf("@@%d %lld %lld\n",u,se[u],fi[u][0].first);
}
void dfs2(int u,int p){
    ans=min(ans,se[u]);
    if(fi[u][0].second)ans=min(ans,fi[u][0].first);
    for(auto it:e[u]){
        int v=it.first,w=it.second;
        if(v==p)continue;
        ll x=se[u]-min(tw[v],sum[v]+w);
        pli y={fi[u][0].first-min(tw[v],sum[v]+w),fi[u][0].second};
        if(fi[u][0].second==v){
            y={fi[u][1].first-min(tw[v],sum[v]+w),fi[u][1].second};
        }
        if(w==0)x+=2,y.first++;
        else x+=w%2,y.first+=(w%2)^1;

        ll cur=min(x,sum[1]-sum[v]);
        se[v]+=cur;
        fi[v][0].first+=cur;
        fi[v][1].second+=cur;

        if(y.second){
            printf("#%d %lld %lld\n",v,x,y.first);
            cur=y.first;
            if(!fi[v][0].second)
                fi[v][0]={cur,u};
            else {
                if(fi[v][0].first>cur){
                    fi[v][1]=fi[v][0];
                    fi[v][0]={cur,u};
                }
                else {
                    if(!fi[v][1].second)
                        fi[v][1]={cur,u};
                    else if(fi[v][1].first>cur)
                        fi[v][1]={cur,u};
                }
            }  
            
        }
        dfs2(v,u);        
    }
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        ans=1e18;
        scanf("%d",&n);
        init();
        for(int i=1;i<n;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            e[u].push_back({v,w});
            e[v].push_back({u,w});
        }
        dfs1(1,0);
        dfs2(1,0);
        printf("%lld\n",ans);
    }


    return 0;
}
/*
2
7
1 2 0
2 3 3
3 4 2
4 5 1
2 6 2
6 7 1
3
1 2 0
2 3 0
*/
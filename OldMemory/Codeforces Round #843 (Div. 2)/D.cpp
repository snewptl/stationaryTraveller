#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=6e5+5;
const ll mod=998244353;
const double eps=1e-10;
vector<int>e[maxn];
int n,a[maxn];
vector<int>pri;
int vis[maxn];
int s,t;
void init(){
    for(int i=2;i*i<=3e5;i++){
        if(!vis[i])pri.push_back(i);
        for(auto j:pri){
            if(1ll*i*j>=3e5)break;
            vis[i*j]=1;
            if(i%j==0)break;
        }
    }
}
int dis[maxn],fa[maxn];
void bfs(){
    queue<int>q;
    dis[s]=1;
    q.push(s);
    while(!q.empty()){
        int p=q.front();q.pop();
        for(auto v:e[p]){
            if(!dis[v]){
                dis[v]=dis[p]+1;
                fa[v]=p;
                q.push(v);
            }
        }
    }
    if(!dis[t])puts("-1");
    else {
        vector<int>ans;
        for(int cur=t;cur!=s;cur=fa[cur]){
            if(cur<=n)ans.push_back(cur);
        }
        ans.push_back(s);
        reverse(ans.begin(),ans.end());
        printf("%d\n",(int)ans.size());
        for(auto it:ans)printf("%d ",it);
        puts("");        
    }

}
int main(){
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for(auto j:pri){
            if(a[i]%j==0){
                while(a[i]%j==0)a[i]/=j; 
                int v=n+j;
                e[v].push_back(i);
                e[i].push_back(v);
            }
        }
        if(a[i]!=1){
            int v=a[i]+n;
            e[v].push_back(i);
            e[i].push_back(v);
        }
    }
    scanf("%d%d",&s,&t);
    bfs();

	return 0;
}
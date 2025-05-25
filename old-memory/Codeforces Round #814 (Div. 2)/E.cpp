#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int k,c[maxn],idx;
struct block{
    ll a[105];
    int dep,lst;
};
queue<block>q;
ll fib[105],sum,pre[105];
bool final(block cur){
    sort(cur.a+1,cur.a+k+1);
    for(int i=1;i<=k;i++){
        if(cur.a[i]!=c[i])return false;
    }
    return true;
}
int vis[105];
bool check(block cur){
    // return true;
    for(int i=1;i<=k;i++)vis[i]=0;
    sort(cur.a+1,cur.a+k+1);
    for(int i=1;i<=k;i++){
        int flag=0;
        for(int j=1;j<=k;j++)if(c[i]==cur.a[j]&&!vis[j])flag=1,vis[j]=1;
        if(flag)continue;
        for(int j=1;j<=k;j++){
            if(vis[j])continue;
            if(c[i]-cur.a[j]<fib[cur.dep+1])return false;
            vis[j]=1;
            break;
        }
    }
    return true;
}
bool bfs(){
    while(!q.empty())q.pop();
    block cur;
    cur.dep=0;
    cur.lst=0;
    for(int i=1;i<=k;i++){
        cur.a[i]=0;
    }
    q.push(cur);
    while(!q.empty()){
        auto p=q.front();q.pop();
        if(final(p))return true;
        block to=p;
        printf("##%d\n",to.dep);
        to.dep=p.dep+1;
        for(int i=1;i<=k;i++){
            if(i==p.lst)continue;
            to.a[i]+=fib[to.dep];
            to.lst=i;
            if(check(to))q.push(to);
            to.a[i]-=fib[to.dep];
        }
    }
    return false;
}
int main(){
    fib[1]=1,fib[2]=1;
    for(int i=3;i<=100;i++){
        fib[i]=fib[i-1]+fib[i-2];
        if(fib[i]>=1e18)break;
    }
    for(int i=1;i<=100;i++){
        pre[i]=pre[i-1]+fib[i];
        if(pre[i]>=1e18)break;
    }
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&k);
        idx=0;
        sum=0;
        for(int i=1;i<=k;i++)scanf("%d",&c[i]),sum+=c[i];
        sort(c+1,c+k+1);
        for(int i=1;i<=100;i++){
            if(sum==fib[i])idx=i;
        }
        if(!idx||idx<k)puts("NO");
        
        else {
            if(bfs())puts("YES");
            else puts("NO");
        }
        
	}


	return 0;
}
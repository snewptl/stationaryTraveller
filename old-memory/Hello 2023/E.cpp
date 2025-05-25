#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int vis[255];
int ask(int cur){
    printf("? %d ",cur);
    for(int i=1;i<=n;i++)printf("%d ",vis[i]);
    puts("");
    fflush(stdout);
    int res;
    scanf("%d",&res);
    return res;
}
int n;
int main(){
	scanf("%d",&n);
    int pre=1;
    for(int i=2;i<=n;i++){
        memset(vis,0,sizeof(vis));
        vis[pre]=vis[i]=1;
        int res=ask(pre);
        if(!res)pre=i;
    }
    


	return 0;
}
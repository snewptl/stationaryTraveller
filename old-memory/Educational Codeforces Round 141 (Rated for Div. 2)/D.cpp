#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const int B=9e4;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int pre[maxn],nxt[maxn];
void ad(int &x,int y){
    x+=y;
    if(x>=mod)x-=mod;
}
int hsh(int x){
    return x+B;
}
void solve(){
    pre[hsh(a[2])]=1;
    for(int i=3;i<=n;i++){
        for(int j=-B;j<=B;j++){
            int x=j,cnt=pre[hsh(j)];
            if(!x)ad(nxt[hsh(a[i])],cnt);
            else ad(nxt[hsh(a[i]+x)],cnt),ad(nxt[hsh(a[i]-x)],cnt);
        }
        // assert(pre!=nxt);
        for(int j=-B;j<=B;j++)pre[hsh(j)]=nxt[hsh(j)],nxt[hsh(j)]=0;
    }
    int res=0;
    for(int i=-B;i<=B;i++)ad(res,pre[hsh(i)]);
    printf("%d\n",res);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    solve();


	return 0;
}
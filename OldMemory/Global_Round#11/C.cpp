#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int maxn=1e5+10;
int r,n,ans;
int x[maxn],y[maxn],t[maxn];
int h[maxn],head,tail;
int main(){
    scanf("%d%d",&r,&n);
    h[tail++]=0,x[head]=1,y[head]=1;
    for(int i=1;i<=n;i++){
        // scanf("%d%d%d",&a[i].t,&a[i].x,&a[i].y);
        scanf("%d%d%d",&t[i],&x[i],&y[i]);
        find();
        
    }
    return 0;
}
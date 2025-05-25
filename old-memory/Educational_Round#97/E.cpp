#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int n,a[maxn],k,b[maxn],ans;
int dp[maxn];
vector<int>c;
int solve(int l,int r){
    c.clear();
    for(int i=l+1;i<r;i++){
        if(a[i]<a[l]||a[i]>a[r])continue;
        auto pos=upper_bound(c.begin(),c.end(),a[i]);
        if(pos==c.end())c.push_back(a[i]);
        else *pos=a[i];
    }
    return c.size();
}
int main(){
    int flag=1;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]-=i;
    }    
    b[k+1]=n+1;
    a[n+1]=2e9+10;
    a[0]=-a[n+1];
    for(int i=1;i<=k;i++){
        scanf("%d",&b[i]);
        if(k!=1&&a[b[i]]<a[b[i-1]])flag=0;
    }

    for(int i=0;i<=k;i++){
        ans+=b[i+1]-b[i]-1-solve(b[i],b[i+1]);
    }
    if(flag)printf("%d",ans);
    else printf("-1");
    return 0;
}
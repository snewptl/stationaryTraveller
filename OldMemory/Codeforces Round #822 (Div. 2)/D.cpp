#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k,a[maxn];
ll pre[maxn],sub[maxn];
bool solve(){
    int le=k,ri=k;
    int xl=k-1,xr=k+1;
    ll sum=a[k];
    ll curl=0,curr=0;
    int flag=0;
    while(!flag){
        flag=1;
        while(xl>=1&&(a[xl]+curl)+sum>=0){
            curl+=a[xl];
            if(pre[le-1]-pre[xl-1]>=0){
                sum+=pre[le-1]-pre[xl-1];
                le=xl;
                curl=0;
            }
            xl--;
            flag=0;
        }
        while(xr<=n&&(a[xr]+curr)+sum>=0){
            curr+=a[xr];
            if(pre[xr]-pre[ri]>=0){
                sum+=pre[xr]-pre[ri];
                ri=xr;
                curr=0;
            }
            xr++;
            flag=0;
        }
    }
    int temp=1;
    for(int i=le-1;i>=1;i--){
        if(sum+pre[le-1]-pre[i-1]<0)temp=0;
    }
    if(temp)return true;
    temp=1;
    for(int i=ri+1;i<=n;i++){
        if(sum+pre[i]-pre[ri]<0)temp=0;
    }
    if(temp)return true;
    return false;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
        for(int i=n;i>=1;i--){
            if(i==n)sub[i]=a[i];
            else sub[i]=a[i]+sub[i+1];
        }
        if(solve())puts("YES");
        else puts("NO");
	}


	return 0;
}
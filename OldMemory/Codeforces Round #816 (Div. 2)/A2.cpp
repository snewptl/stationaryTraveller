#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=1e9+7;
const int maxn=1e6+5;
const double eps=1e-10;
int n;
int a[maxn];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if(n%2){
        if(n==3){
            printf("%d 6\n",(a[3]-a[1])*2);
        }
        else {
            ll temp=1;
            for(int i=1;i<=n/2;i++)temp*=i,temp%=mod;
            temp*=temp,temp%=mod;
            temp*=2*n,temp%=mod;
            ll sum=0;
            for(int i=1;i<=n/2;i++)sum-=a[i];
            for(int i=n/2+2;i<=n;i++)sum+=a[i];
            sum*=2;
            printf("%lld %lld\n",sum,temp);
        }
    }
    else {
        ll temp=1;
        for(int i=1;i<=n/2;i++)temp*=i,temp%=mod;
        temp*=temp,temp%=mod;
        temp*=2,temp%=mod;
        ll sum=0;
        for(int i=1;i<=n/2;i++)sum-=a[i];
        for(int i=n/2+1;i<=n;i++)sum+=a[i];
        sum*=2;    
        printf("%lld %lld\n",sum,temp);    
    }

    return 0;
}
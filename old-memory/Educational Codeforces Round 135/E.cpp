#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxn=2e5+5;
const double eps=1e-10;

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
    if (b==0)
    {
        d=a; x=1; y=0;
    } else
    {
        exgcd(b,a%b,d,y,x);
        y-=x*(a/b); 
    }
}

int n,m;
ll vr[maxn],vb[maxn];
ll sum;
vector<int>more_red,more_black,pre_red,pre_black;
ll ans[maxn];
int cntr,cntb;
void init(){
    for(int i=1;i<=n;i++){
        if(vr[i]>vb[i])more_black.push_back(vr[i]-vb[i]);
        else more_red.push_back(vb[i]-vr[i]);
    }
    sort(more_black.begin(),more_black.end());
    sort(more_red.begin(),more_red.end());
    pre_red.resize(more_red.size());
    pre_black.resize(more_black.size());
    ans[cntr]=sum;
    for(int i=0;i<pre_red.size();i++){
        if(i)pre_red[i]=pre_red[i-1];
        pre_red[i]+=more_red[i];
        ans[cntr+i+1]=sum-pre_red[i];
    }
    for(int i=0;i<pre_black.size();i++){
        if(i)pre_black[i]=pre_black[i-1];
        pre_black[i]+=more_black[i];
        ans[cntr-i-1]=sum-pre_black[i];
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&vr[i],&vb[i]);
        sum+=max(vr[i],vb[i]);
        if(vr[i]>vb[i])cntr++;
        else cntb++;
    }
    init();
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        ll a,b,d,x,y;
        scanf("%lld%lld",&a,&b);
        exgcd(a,b,d,x,y);
        if(n%d!=0)puts("-1");
        else {
            ll res=-1e9;
            x*=n/d,y*=n/d;
            ll x0=cntr/a;
            a/=d,b/=d; 
            ll temp=(x0-x)/b-2;
            for(int j=0;j<10;j++){
                temp++;
                ll x1=x,y1=y;
                x1+=temp*b,y1-=temp*a;
                if(x1<0){
                    temp=(-x1+b-1)/b;
                    x1+=temp*b,y1-=temp*a;
                }
                if(y1<0){
                    temp=(-y1+a-1)/a;
                    y1+=temp*a,x1-=temp*b;
                }               
                if(x1>=0&&y1>=0)res=max(res,ans[x1*a*d]);                     
            }       
            // printf("@@%lld %lld %lld %lld\n",x1,y1,x2,y2);
            if(res<0)puts("-1");
            else printf("%lld\n",res);
        }
    }

    return 0;
}
/*
10
3 1
2 3
1 1
2 1
6 3
1 4
4 3
1 3
5 3
5 4
2
3 5
1 6
*/
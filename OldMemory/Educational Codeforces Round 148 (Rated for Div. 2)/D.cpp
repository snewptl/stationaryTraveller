#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
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
int n,q;
int a[maxn],k[maxn],pre[maxn];
vector<int>vec;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;//cin>>T;
    while(T--){
        cin>>n>>q;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            pre[i]=a[i]-i+1;
            if(i>1)pre[i]=min(pre[i],pre[i-1]);
        }
        ll sum=0,sumdel=0;
        for(int i=1;i<=n;i++){
            sum+=(a[i]-i+1)-pre[n];
        }
        for(int i=1;i<n;i++){
            sumdel+=(a[i]-i+1)-pre[n-1];
        }
        // cout<<" "<<pre[n]<<" "<<sum<<'\n';
        a[n+1]=2e9;
        for(int i=1;i<=q;i++)cin>>k[i];
        for(int cs=1;cs<=q;cs++){
            int opt=k[cs];
            if(opt<=n)
                cout<<min(pre[opt]+opt,a[opt+1])<<' ';
            else {
                int rem=opt-n,res;
                if(rem%2==0){
                    rem/=2;
                    if(sum>=rem)res=pre[n]+opt;
                    else {
                        rem-=sum;
                        res=pre[n]+opt-(rem+n-1)/n;
                    }
                }
                else {
                    rem++;
                    rem/=2;
                    ll cur=sumdel;
                    int mn=min(pre[n-1],a[n]-opt);
                    cur+=1ll*(pre[n-1]-mn)*(n-1)+(a[n]-opt-mn);
                    if(cur>=rem)res=mn+opt;
                    else {
                        rem-=cur;
                        res=mn+opt-(rem+n-1)/n;
                    }
                }
                cout<<res<<' ';
            }
        }
    }

    return 0;
}
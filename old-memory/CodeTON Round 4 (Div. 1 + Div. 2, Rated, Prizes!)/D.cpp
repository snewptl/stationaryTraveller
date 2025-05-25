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
int q;
pll seg;
pll merge(pll a,pll b){
    return {max(a.first,b.first),min(a.second,b.second)};
}
ll check(ll h,ll a,ll b){
    if(h<=a)return 1;
    ll d=(h-a+a-b-1)/(a-b)+1;
    return d;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>q;
        seg={-1,-1};
        while(q--){
            ll a,b,n,opt;
            cin>>opt;
            // cout<<" $$"<<seg.first<<" "<<seg.second<<"$$\n";
            if(opt==1){
                cin>>a>>b>>n;
                pll temp={(a-b)*(n-1)+b+1,(a-b)*(n-1)+a};
                if(n==1)temp={1,a};
                if(seg.first==-1){
                    seg=temp;
                    cout<<"1 ";
                }
                else {
                    temp=merge(temp,seg);
                    if(temp.first<=temp.second){
                        seg=temp;
                        cout<<"1 ";
                    }
                    else cout<<"0 ";
                }
            }
            else {
                cin>>a>>b;
                // ll h=seg.first,d;
                // if(h<=b){
                //     d=1;
                //     if(a+1<=seg.second)cout<<"-1 ";
                //     else cout<<"1 ";
                // }
                // else {
                //     d=(h-a+a-b-1)/(a-b)+1;
                //     h=(d-1)*(a-b)+b+1;
                //     // cout<<"$$"<<h<<" "<<d<<" $$\n";
                //     if(h<=seg.second){
                //         if(h+(a-b)<=seg.second)cout<<"-1 ";
                //         else cout<<d<<' ';
                //     }
                //     else {
                //         assert(0);
                //     }
                // }
                if(check(seg.first,a,b)!=check(seg.second,a,b))cout<<"-1 ";
                else cout<<check(seg.first,a,b)<<" ";
            }
        }
        cout<<'\n'; 
    }

    return 0;
}
/*
1
9
1 2 1 6
1 8 5 6
1 4 2 7
2 9 1
1 5 1 4
1 5 2 7
1 7 1 9
1 9 1 4
2 10 8
*/
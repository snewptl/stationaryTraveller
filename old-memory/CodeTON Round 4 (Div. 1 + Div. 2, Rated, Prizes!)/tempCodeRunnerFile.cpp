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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>q;
        seg={-1,-1};
        while(q--){
            int a,b,n,opt;
            cin>>opt;
            // cout<<" $$"<<seg.first<<" "<<seg.second<<"$$\n";
            if(opt==1){
                cin>>a>>b>>n;
                pll temp={(a-b)*(n-1)+b+1,(a-b)*(n-1)+a};
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
                ll h=seg.first,d;
                d=min((h-(b+1)+a-b-1)/(a-b),
                    (h-a+a-b-1)/(a-b))+1;
                h=(d-1)*(a-b)+b+1;
                // cout<<"$$"<<h<<" "<<d<<" $$\n";
                if(h<=seg.second){
                    if(h+(a-b)<=seg.second)cout<<"-1 ";
                    else cout<<d<<' ';
                }
                else {
                    assert(0);
                }
            }
        }
        cout<<'\n'; 
    }

    return 0;
}
/*
1
3
1 3 2 5
2 4 1
2 3 2
*/
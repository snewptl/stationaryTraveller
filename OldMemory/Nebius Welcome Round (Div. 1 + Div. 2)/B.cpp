#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxm=1e6+5;
const int maxn=1e5+5;
const double eps=1e-10;
int n,k,d,w;
queue<int>q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>k>>d>>w;
        int ans=0;
        int rem=0,tim=0;
        for(int i=1;i<=n;i++){
            int t;cin>>t;
            q.push(t);
            while(!q.empty()&&t-q.front()>w){
                if(q.front()-tim>d)rem=0;
                if(rem)rem--;
                else rem=k-1,tim=q.front()+w,ans++;
                q.pop();
            }        
        }
        while(!q.empty()){
            if(q.front()-tim>d)rem=0;
            if(rem)rem--;
            else rem=k-1,ans++,tim=q.front()+w;
            q.pop();
        }
        cout<<ans<<'\n';
    }

    return 0;
}
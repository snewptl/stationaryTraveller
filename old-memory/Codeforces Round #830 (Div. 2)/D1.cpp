#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int q;
set<ll>s;
map<ll,ll>mp;
int main(){
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        char opt[5];
        ll x;
        scanf("%s%lld",opt,&x);
        if(opt[0]=='+'){
            s.insert(x);
        }
        else {
            if(!mp.count(x))mp[x]=x;
            while(s.count(mp[x]))mp[x]+=x;
            printf("%lld\n",mp[x]);
        }
        
    }

	return 0;
}
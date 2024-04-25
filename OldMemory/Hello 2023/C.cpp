#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
vector<int>vec;
int solve(){
    multiset<int>s;
    ll sum=0;
    int res=0;
    for(auto it:vec){
        if(it>=0)sum+=it;
        else {
            s.insert(it);
            sum+=it;
            while(sum<0){
                res++;
                sum+=(*s.begin())*(-2);
                s.erase(s.begin());
            }
        }
    }
    return res;
}
int n,m,a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        int ans=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=m+1;i<=n;i++)vec.push_back(a[i]);
        ans+=solve();
        vec.clear();
        for(int i=m;i>1;i--)vec.push_back(-a[i]);
        ans+=solve();
        vec.clear();
        printf("%d\n",ans);
	}


	return 0;
}
/*
1
1 1
1
*/
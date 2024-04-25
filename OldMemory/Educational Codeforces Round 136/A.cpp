#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
void solve(){
    // if(min(n,m)<=1||max(n,m)<=2){
    //     puts("1 1");
    //     return ;        
    // }
    // if(n<=m){
    //     puts("2 3");
    // }
    // else puts("3 2");
    printf("%d %d\n",(n+1)/2,(m+1)/2);
}

int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&m);
        solve();
	}


	return 0;
}
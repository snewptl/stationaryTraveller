#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n/2;i++){
            printf("%d %d ",n-i+1,i);
        }
        if(n%2)printf("%d\n",(n+1)/2);
        else puts("");
	}


	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
        }
        if(m<n)puts("YES");
        else puts("NO");
	}


	return 0;
}
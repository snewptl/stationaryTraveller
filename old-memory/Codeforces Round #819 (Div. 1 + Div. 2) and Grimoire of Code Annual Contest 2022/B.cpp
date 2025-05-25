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
        if(m<n)puts("NO");
        else {
            if(n%2){
                puts("YES");
                for(int i=1;i<n;i++)printf("1 ");
                printf("%d\n",m-n+1);
            }
            else {
                if(m%2)puts("NO");
                else {
                    puts("YES");
                    for(int i=1;i<=n-2;i++)printf("1 ");
                    int cur=(m-n+2)/2;
                    printf("%d %d\n",cur,cur);
                }
            }
        }
	}


	return 0;
}
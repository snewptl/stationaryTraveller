#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int x,y,n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        if(n==2){
            printf("YES\n1 1\n");
        }
        else if(n==3){
            puts("NO");
        }
        else {
            x=n-(n+1)/2-1;
            y=-((n+1)/2-1);
            puts("YES");
            for(int i=1;i<=n/2;i++){
                printf("%d %d ",x,y);
            }
            if(n%2)printf("%d",x);
            puts("");            
        }

	}


	return 0;
}
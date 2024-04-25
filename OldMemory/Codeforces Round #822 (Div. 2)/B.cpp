#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            printf("1 ");
            for(int j=2;j<i;j++)
                printf("0 ");
            if(i>1)printf("1");
            puts("");
        }
	}


	return 0;
}
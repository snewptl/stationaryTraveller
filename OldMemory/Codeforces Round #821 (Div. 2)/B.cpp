#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,x,y;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d%d",&n,&x,&y);
        if(x<y)swap(x,y);
        if(y!=0)puts("-1");
        else {
            if(!x)puts("-1");
            else if((n-1)%x!=0)puts("-1");
            else {
                for(int i=2;i<=n;i+=x){
                    for(int j=0;j<x;j++)printf("%d ",i);
                }
                puts("");
            }
        }
	}


	return 0;
}
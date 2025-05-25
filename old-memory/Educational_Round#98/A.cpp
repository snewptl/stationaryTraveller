#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
int x,y;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&x,&y);
		int cx=min(x,y),cy=max(x,y);
		printf("%d\n",max(cy-cx-1,0)+x+y);
    }


    return 0;
}
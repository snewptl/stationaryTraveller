#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int l,r;
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d%d",&l,&r);
		if(l*2>r){
			printf("%d\n",r-l);
		}
		else printf("%d\n",(r-1)/2);
    }


    return 0;
} 
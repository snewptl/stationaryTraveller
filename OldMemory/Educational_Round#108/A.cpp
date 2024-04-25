#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int r,b,d;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&r,&b,&d);
		int mn=min(r,b);
		int mx=max(r,b);
		if(!d){
			if(r!=b)printf("NO\n");
			else printf("YES\n");
		}
		else {
			if((mx-mn-1)/d+1>mn)printf("NO\n");
			else printf("YES\n");			
		}

    }


    return 0;
}
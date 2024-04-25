#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int q,d;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&q,&d);
		for(int i=1;i<=q;i++){
			int x;
			scanf("%d",&x);
			int y=x/d,z=x%d;
			if(!z)printf("YES\n");
			else if(y>=10)printf("YES\n");
			else {
				int flag=0;
				for(int i=1;i<y;i++){
					if((i*d+z)%10==0)flag=1;
				}
				if(flag)printf("YES\n");
				else printf("NO\n");
			}
		}
    }


    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int a,b;
int main(){
    int T;scanf("%d",&T);
    while(T--){
		int cnt=0,ans=1e9;
        scanf("%d%d",&a,&b);
		for(int i=0;i<=100;i++){
			
			int x=a,y=b+i;if(y==1)continue;
			cnt=0;
			while(x){
				x/=y;cnt++;
			}	
			ans=min(ans,cnt+i);
		}

		printf("%d\n",ans);
    }


    return 0;
}
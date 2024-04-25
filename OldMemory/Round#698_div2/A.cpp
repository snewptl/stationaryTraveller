#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int a[105];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		int n,k=0,ans=0;
        scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1])k++;
			else {
				ans=max(ans,k);k=0;
			}
		}
		ans=max(ans,k);
		printf("%d\n",ans+1);
    }


    return 0;
}
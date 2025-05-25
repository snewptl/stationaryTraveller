#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,a[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		int p=1,ans=0,mn=1e9;
		while(p<=n&&a[p]<=0){
			if(p!=1){
				mn=min(mn,abs(a[p]-a[p-1]));
			}			
			ans++,p++;

		}
		if(p<=n&&a[p]<=mn)ans++;
		
		printf("%d\n",ans);
    }
 
 
    return 0;
}
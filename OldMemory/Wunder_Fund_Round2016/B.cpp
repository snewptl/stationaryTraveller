#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[55];
int n;
int main(){
	scanf("%d",&n);
    for(int i=1;i<=n;i++){
		int mx=0;
		for(int j=1;j<=n;j++){
			int x;scanf("%d",&x);
			mx=max(mx,x);
		}
		ans[i]=mx;
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==n-1){
			ans[i]=n;break;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,a[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d",&n);
		int flag=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			int x=sqrt(a[i]);
			if(x*x!=a[i])flag=1;
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
    }	


    return 0;
}
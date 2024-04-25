#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
int a[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int mn=2e9,p=0;
		for(int i=1;i<=n;i++){
			if(a[i]<mn){
				mn=a[i];
				p=i;
			}
		}
		if(p!=1){
			printf("%d\n",n);
			printf("%d %d %d %d\n",1,p,mn,mn+1);
		}
		else {
			printf("%d\n",n-1);
		}
		int sgn=1;
		for(int i=2;i<=n;i++){
			printf("%d %d %d %d\n",1,i,mn,mn+sgn);
			sgn^=1;
		}
    }


    return 0;
}
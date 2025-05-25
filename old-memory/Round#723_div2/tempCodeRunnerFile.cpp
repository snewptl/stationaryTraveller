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
		for(int i=0;i<2*n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n*2);
		for(int i=0;i<2*n;i++)printf("%d ",a[i]);
		printf("\n");
    }


    return 0;
}
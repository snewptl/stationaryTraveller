#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,sum;
int a[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		sum=0;
        scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum==n)printf("0\n");
		else {
			if(sum>n)printf("%d\n",sum-n);
			else printf("1\n");
		}
    }


    return 0;
}
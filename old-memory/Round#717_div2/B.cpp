#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,a[maxn];
int main(){
    int T;scanf("%d",&T);

    while(T--){
        scanf("%d",&n);
		int sum=0,temp=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum^=a[i];
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			temp^=a[i];
			if(temp==sum)temp=0,flag++;
		}
		if(flag>=2||sum==0)printf("YES\n");
		else printf("NO\n");
    }


    return 0;
}
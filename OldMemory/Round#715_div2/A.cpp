#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int cnt1,cnt2;
int n,a[maxn];
int b[maxn];
int c[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        cnt1=cnt2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]%2)b[++cnt1]=a[i];
			else c[++cnt2]=a[i];
		}
		for(int i=1;i<=cnt1;i++)printf("%d ",b[i]);
		for(int i=1;i<=cnt2;i++)printf("%d ",c[i]);
		printf("\n");
    }


    return 0;
}
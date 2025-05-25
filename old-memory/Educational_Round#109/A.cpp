#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int a[10],b[10];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        for(int i=0;i<4;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		if(a[0]>a[1])swap(a[0],a[1]);
		if(a[2]>a[3])swap(a[2],a[3]);
		sort(b,b+4);
		if(a[0]==b[2]||a[2]==b[2])printf("NO\n");
		else printf("YES\n");
		
    }


    return 0;
}
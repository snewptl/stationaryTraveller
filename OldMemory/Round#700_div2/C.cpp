#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int a[maxn];
int main(){
    int n;scanf("%d",&n);
	a[0]=1e9,a[n+1]=1e9;
	int l=1,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(!a[mid]){
			printf("? %d\n",mid);
			fflush(stdout);	
			scanf("%d",&a[mid]);	
		}
		if(!a[mid+1]){
			printf("? %d\n",mid+1);
			fflush(stdout);	
			scanf("%d",&a[mid+1]);	
		}
		if(a[mid]>a[mid+1])l=mid+1;
		else r=mid;

	}
	printf("! %d",l);
    return 0;
}
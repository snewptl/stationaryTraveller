#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int a[maxn];
int main(){
    int n;scanf("%d",&n);
	a[0]=1e9,a[n+1]=1e9;
	int l=0,r=n+1;
	while(r-l+1>4){
		int mid=l+r>>1;
		if(!a[mid]){
			printf("? %d\n",mid);
			fflush(stdout);	
			scanf("%d",&a[mid]);	
		}
		if(a[mid]>a[l])r=mid;
		else if(a[mid]>a[r])l=mid;
		else {
			int le=(mid+l)/2;
			int ri=(mid+r)/2;
			if(!a[le]){
				printf("? %d\n",le);
				fflush(stdout);		
				scanf("%d",&a[le]);		
			}
			if(!a[ri]){
				printf("? %d\n",ri);
				fflush(stdout);		
				scanf("%d",&a[ri]);		
			}
			if(a[mid]>a[le])r=mid;
			else if(a[mid]>a[ri])l=mid;
			else l=le,r=ri;
		}
		
	}
	for(int i=l;i<=r;i++){
		if(!a[i]){
			printf("? %d\n",i);
			fflush(stdout);	
			scanf("%d",&a[i]);				
		}
	}
	for(int i=l+1;i<=r-1;i++){
		if(a[i]<a[i-1]&&a[i]<a[i+1]){
			printf("%d\n",i);
			fflush(stdout);	
			break;
		}
	}

    return 0;
}
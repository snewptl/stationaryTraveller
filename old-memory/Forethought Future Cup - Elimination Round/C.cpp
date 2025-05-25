#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int mx,n;
int query(int l,int r){
	printf("%d %d 1 ",1,r-l+1);
	for(int i=l;i<=r;i++)printf("%d ",i);
	printf("\n");fflush(stdout);
	int x;scanf("%d",&x);
	return x;
}
int main(){
    int T=1;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		mx=query(2,n);
		int l=2,r=n;
		while(l<r){
			int mid=l+r>>1;
			int d=query(l,mid);
			if(d==mx)r=mid;
			else l=mid+1;
		}
		printf("%d %d %d ",1,n-1,l);
		for(int i=1;i<=n;i++)if(i!=l)printf("%d ",i);
		printf("\n");fflush(stdout);
		scanf("%d",&mx);
		printf("-1 %d\n",mx);
		fflush(stdout);
    }


    return 0;
}
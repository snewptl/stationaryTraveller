#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
int main(){
	scanf("%d",&n);
	int k=(int)sqrt(n+0.5);
	for(int i=0;i*k<=n;i++){
		for(int j=k;j>=1;j--){
			if(i*k+j>n)continue;
			printf("%d ",i*k+j);
		}
	}
	printf("\n");


    return 0;
}
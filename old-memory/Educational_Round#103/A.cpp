#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int gcd(int x,int y){
	return y?(y,x%y):x;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
		int n,k;
        scanf("%d%d",&n,&k);
		if(n>k){
			if(n%k!=0)printf("2\n");
			else printf("1\n");
		}
		else printf("%d\n",(k-1)/n+1);
    }


    return 0;
}
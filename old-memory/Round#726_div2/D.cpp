#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e9+10;
int dp[100005];
int n;
int mi[50];
int main(){
    int T;scanf("%d",&T);
	// int ed=sqrt(maxn);
	// dp[1]=0;
	// for(int i=2;i<=10000;i++){
	// 	for(int j=2;j<i;j++){
	// 		if(i%j==0){
	// 			if(!dp[i-j]){
	// 				dp[i]=1;
	// 				break;
	// 			}
	// 		}
	// 	}
	// 	if(dp[i]&&i%2==1)
	// 	printf("%d\n",i);
	// 	// int sum=0;
	// 	// if(dp[i]){
	// 	// 	int x=i;
	// 	// 	for(int j=2;j*j<=x;j++){
	// 	// 		if(x%j==0){
	// 	// 			sum++;
	// 	// 			while(x%j==0)x/=j;
	// 	// 		}
	// 	// 	}
	// 	// 	if(x!=1)sum++;
	// 	// 	printf("%d\n",sum);
	// 	// }
		
	// }
    while(T--){
        scanf("%d",&n);
		if(n%2==0){
			int flag=0;
			for(int i=1;i<=30;i+=2){
				if((1<<i)==n)flag=1;
			}
			if(!flag)printf("Alice\n");
			else printf("Bob\n");
		}
		else printf("Bob\n");
    }


    return 0;
}
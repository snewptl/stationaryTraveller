#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
char s[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%s",&n,s);
		int flag=0;
		for(int i=0;i<n/2;i++){
			if(s[i]=='0'){
				printf("%d %d %d %d\n",i+1,n,i+2,n);
				flag=1;
				break;
			}
		}
		if(!flag){
			for(int i=n/2;i<n;i++){
				if(s[i]=='0'){
					printf("%d %d %d %d\n",1,i+1,1,i);
					flag=1;		
					break;					
				}
		
			}
		}
		if(!flag){
			printf("%d %d %d %d\n",1,n-1,2,n);
		}
    }


    return 0;
}
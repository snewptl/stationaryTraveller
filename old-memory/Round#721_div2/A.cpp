#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
		int p=0;
		for(int i=0;i<=n;i++){
			if((1<<i)>n){
				p=i-1;break;
			}
		}
		printf("%d\n",(1<<p)-1);
    }


    return 0;
}
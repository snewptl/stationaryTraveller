#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
char s[105];
int n;
int main(){
    int T;scanf("%d",&T);
    while(T--){
		int flag=0;
		scanf("%d%s",&n,s);
		for(int i=1;i<n;i++){
			if(s[i]!=s[i-1]){
				printf("%d %d\n",i,i+1);
				flag=1;
				break;
			}
		}
		if(!flag)printf("-1 -1\n");
    }


    return 0;
}
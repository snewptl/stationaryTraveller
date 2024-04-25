#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
char s[105];
int n;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%s",&n,s);
		int flag=-1;
		for(int i=0;i<n;i++){
			if(s[i]=='8'){
				flag=0;
				if(n-i<11)flag=1;
				break;
			}
		}
		if(flag==-1||flag==1)printf("NO\n");
		else printf("YES\n");
    }


    return 0;
}
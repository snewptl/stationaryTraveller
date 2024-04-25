#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int main(){
    int T;scanf("%d",&T);
    while(T--){
		char s[55];
        scanf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(i%2){
				if(s[i]=='z')s[i]='y';
				else s[i]='z';
			}
			else {
				if(s[i]=='a')s[i]='b';
				else s[i]='a';
			}
		}
		printf("%s\n",s);
    }


    return 0;
}
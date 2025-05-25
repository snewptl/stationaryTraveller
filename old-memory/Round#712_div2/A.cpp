#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
char s[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",s);
		int len=strlen(s);
		int flag=0;
		for(int i=0;i<len/2;i++){
			if(s[i]!=s[len-i-1])flag=1;
		}
		if(flag){
			printf("YES\n");
			for(int i=0;i<len/2;i++)printf("%c",s[i]);
			printf("a");
			for(int i=len/2;i<len;i++)printf("%c",s[i]);
			printf("\n");
		}
		else {
			flag=0;
			for(int i=0;i<len;i++)if(s[i]!='a')flag=1;
			if(!flag)printf("NO\n");
			else {
				printf("YES\n");
				int p=-1;
				for(int i=0;i<len/2;i++){
					if(s[i]!='a'){p=i;break;}
				}
				if(p==-1)p=len/2;
				for(int i=0;i<p;i++)printf("%c",s[i]);
				printf("a");
				for(int i=p;i<len;i++)printf("%c",s[i]);
				printf("\n");
			}
		}
    }


    return 0;
}
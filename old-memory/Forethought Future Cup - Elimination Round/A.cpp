#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
char s[maxn];
int main(){
		int cnt=0;
        scanf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]=='a')cnt++;
		}
		while(cnt*2<=len)len--;
		printf("%d\n",len);

    return 0;
}
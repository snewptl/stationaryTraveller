#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
char s[maxn];
int len;
int l[maxn],r[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%s",&len,s);
		for(int i=0;i<=len;i++){
			l[i]=r[i]=0;
		}
		for(int i=2;i<=len;i+=2){
			if(s[i-1]=='L'&&s[i-2]=='R')l[i]=l[i-2]+2;
			else {
				if(s[i-1]=='L')l[i]=1;
				else l[i]=0;
			}
		}
		if(s[0]=='L')l[1]=1;
		for(int i=3;i<=len;i+=2){
			if(s[i-1]=='L'&&s[i-2]=='R')l[i]=l[i-2]+2;
			else {
				if(s[i-1]=='L')l[i]=1;
				else l[i]=0;
			}
		}
		for(int i=len-2;i>=0;i-=2){
			if(s[i]=='R'&&s[i+1]=='L')r[i]=r[i+2]+2;
			else {
				if(s[i]=='R')r[i]=1;
				else r[i]=0;
			}
		}
		if(s[len-1]=='R')r[len-1]=1;
		for(int i=len-3;i>=0;i-=2){
			if(s[i]=='R'&&s[i+1]=='L')r[i]=r[i+2]+2;
			else {
				if(s[i]=='R')r[i]=1;
				else r[i]=0;
			}
		}
		for(int i=0;i<=len;i++){
			printf("%d ",l[i]+r[i]+1);
		}
		printf("\n");
    }


    return 0;
}
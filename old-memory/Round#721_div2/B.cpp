#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
char s[maxn];
int a,b;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%s",&n,s);
		int cnt=0,flag=0;
		a=b=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0')cnt++;
		}
		for(int i=0;i<n;i++){
			if(s[i]!=s[n-1-i])flag++;
			if(i==(n-1)/2)break;
		}
		cnt-=flag;
		if(cnt){
			if(cnt==1)b++;
			else if(cnt==3)a++;
			else if(cnt%2){
				cnt--;
				if(cnt%2)b++;
				else a++;
			}
			else b+=2;					
		}
		a+=flag;
		if(flag==0){
			if(a>b)printf("ALICE\n");
			else if(a<b)printf("BOB\n");
			else printf("DRAW\n");			
		}
		else {
			if(a>b)printf("ALICE\n");
			else {
				a-=flag;
				swap(a,b);
				b++;
				a+=flag-1;
				if(a>b)printf("ALICE\n");
				else if(a<b)printf("BOB\n");
				else printf("DRAW\n");					
			}
				
		}
    }
 
 
    return 0;
}
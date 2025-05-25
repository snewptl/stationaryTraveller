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
		int t=0,m=0,flag=1;
		int sum1=0,sum2=0;
		for(int i=0;i<n;i++){
			if(s[i]=='T'){
				t++;
				sum1++;
			}
			else {
				sum2++;
				if(t>m)m++;
				else flag=0;
			}
		}
		t=0,m=0;
		for(int i=n-1;i>=0;i--){
			if(s[i]=='T'){
				t++;
			}
			else {
				if(t>m)m++;
				else flag=0;
			}
		}
		if(sum1!=2*sum2)flag=0;
		if(flag)printf("YES\n");
		else printf("NO\n");
    }


    return 0;
}
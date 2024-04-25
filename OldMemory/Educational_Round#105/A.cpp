#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int a[10];
char s[60];
int len;
bool check(){
	stack<int>st;
	for(int i=0;i<len;i++){
		if(st.empty()){
			if(a[s[i]-'A']!=1){
				return false;
			}
			else st.push(1);
		}
		else {
			if(a[s[i]-'A']==2)st.pop();
			else st.push(1);
		}
	}
	if(!st.empty())return false;
	return true;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",s);
		int flag=0;
		len=strlen(s);
		for(int i=0;i<3;i++)a[i]=0;
		a[s[0]-'A']=1;
		if(a[s[len-1]-'A'])flag=1;
		else a[s[len-1]-'A']=2;
		for(int i=0;i<3;i++){
			if(!a[i]){
				a[i]=1;
				if(!check()){
					a[i]=2;
					if(!check())flag=1;
				}
			}
		}
		if(flag)printf("NO\n");
		else printf("YES\n");

    }


    return 0;
}
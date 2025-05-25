#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int m,h;
int h1,h2,m1,m2;
int res[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
bool check(){
	if(res[m1]==-1||res[m2]==-1||res[h1]==-1||res[h2]==-1)return false;
	if(res[m2]*10+res[m1]>=h)return false;
	if(res[h2]*10+res[h1]>=m)return false;
	return true;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&h,&m);
		char s[10];
		scanf("%s",s);
		h1=s[0]-'0';
		h2=s[1]-'0';
		m1=s[3]-'0';
		m2=s[4]-'0';
		// scanf("%d%d:%d%d",&h1,&h2,&m1,&m2);
		while(true){
			if(check()){
				printf("%d%d:%d%d\n",h1,h2,m1,m2);
				break;
			}
			m2++;
			if(m2>=10)m2=0,m1++;
			if(m1*10+m2>=m)h2++,m1=0,m2=0;
			if(h2>=10)h2=0,h1++;
			if(h1*10+h2>=h)h1=0,h2=0;
		}
    }


    return 0;
}
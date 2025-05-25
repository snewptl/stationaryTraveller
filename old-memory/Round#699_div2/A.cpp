#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
char s[maxn];
int main(){

    int T;scanf("%d",&T);
    while(T--){
    	int x,y,dx=0,dy=0,ri=0,le=0,up=0,dn=0;
		scanf("%d%d",&x,&y);
		scanf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]=='R')dx++,ri++;
			if(s[i]=='L')dx--,le++;
			if(s[i]=='U')dy++,up++;
			if(s[i]=='D')dy--,dn++;
		}
		if(((x>=0&&x<=ri)||(x<0&&x>=-le))
			&&((y>=0&&y<=up)||(y<0&&y>=-dn)))printf("YES\n");
		else printf("NO\n");
    }


    return 0;
}
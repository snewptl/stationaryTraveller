#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
char s[maxn];
int n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%s",s);
        int a=1e9,b=1e9;
        n=strlen(s);
        for(int i=0;i<n;i++){
            if(s[i]=='a')a=min(a,i);
            if(s[i]=='b')b=min(b,i);
        }
        int pos1,pos2;
        if(a==1e9||b==1e9){
            pos1=0,pos2=n-2;
        }
        else if(a<=b){
            if(b!=n-1){
                pos1=b-1;
                pos2=n-2;                
            }
            else {
                pos1=n-3;
                pos2=n-2;
            }

        }
        else {
            if(a!=n-1){
                pos1=a-1;
                pos2=a;               
            }
            else {
                pos1=0;
                pos2=n-2;
            }

        }

        for(int i=0;i<=pos1;i++)printf("%c",s[i]);
        printf(" ");
        for(int i=pos1+1;i<=pos2;i++)printf("%c",s[i]);
        printf(" ");
        for(int i=pos2+1;i<n;i++)printf("%c",s[i]);
        puts("");
	}


	return 0;
}
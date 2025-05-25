#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e6+5;
const ll mod=998244353;
const double eps=1e-10;
int n,q;
char s[maxn],S[maxn],;
int nxt[maxn],to[maxn][30];
map<string,int>mp;
string t;
void Getnxtt(){
	nxt[0] = 0;
	int i = 1;
	int len = 0;
	while(i < n){
		if(s[i] == s[len]){
			len++;
			nxt[i] = len;
			i++;
		}else{
			if(len > 0){
				len = nxt[len - 1];
			}else{
				nxt[i] = len;
				i++;
			}
		}
	}
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
        scanf("%s%d",S,&q);
        n=strlen(S);
        mp.clear();
        for(int j=0;j<n;j++)s[j]=S[j];
        Getnxtt();
        for(int i=1;i<=q;i++){
            int res=0;
            cin>>t;
            string nw="";
            int cur=nxt[n-1];

            for(int j=0;j<t.size();j++){
                S[j+n]=t[j];
                while(cur){
                    if(S[cur]==t[j]){
                        nxt[j+n]=++cur,to[];
                        break;
                    }
                    else cur=nxt[cur-1];
                }
                if(!cur){
                    if(S[cur]==t[j])nxt[j+n]=++cur;
                    else cur=0,nxt[j+n]=0;
                }
                printf("%d ",nxt[j+n]);
            }
            puts("");

        }    
        
	}


	return 0;
}
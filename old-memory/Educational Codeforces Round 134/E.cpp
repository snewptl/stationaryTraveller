#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e6+5;
const ll mod=998244353;
const double eps=1e-10;
int n,q;
char s[maxn],S[maxn];
int nxt[maxn],res[15],nxtS[maxn];
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
        int sz=strlen(S);
        n=sz;
        mp.clear();
        for(int j=0;j<sz;j++)s[j]=S[j];
        Getnxtt();
        for(int i=0;i<sz;i++)nxtS[i]=nxt[i];
        int cur=sz-1;
        while(cur>=0){
            string temp="";
            for(int i=nxt[cur];i<=min(sz-1,nxt[cur]+10);i++){
                temp.push_back(S[i]);
                mp[temp]=max(mp[temp],nxt[cur]+(int)temp.size());
            }
            cur=nxt[cur]-1;
        }
        for(int i=1;i<=q;i++){
            cin>>t;
            string nw="";
            int res=0;
            int temp=nxtS[sz-1];
            for(int j=0;j<t.size();j++){
                nw.push_back(t[j]);
                for(int k=0;k<nw.size();k++)s[k]=S[k];
                for(int k=nw.size();k<nw.size()*2;k++)s[k]=t[k-nw.size()];
                n=nw.size()*2;
                Getnxtt();
                int cur=n-1;
                while(nxt[cur]>=nw.size()){
                    cur=nxt[cur]-1;
                }
                res=max(mp[nw],nxt[cur]);  

                int flag=0;
                S[j+sz]=t[j];
                while(temp&&!flag){
                    if(sz-temp>20){
                        flag=1;break;
                    }
                    if(S[temp]==t[j]){
                        nxtS[j+sz]=++temp;
                        break;
                    }
                    else temp=nxtS[temp-1];
                }
                if(!temp){
                    if(S[temp]==t[j])nxtS[j+sz]=++temp;
                    else temp=0,nxtS[j+sz]=0;
                }
                if(!flag)res=max(res,nxtS[j+sz]);
                printf("%d ",res);
            }
            puts("");
        }    
        
	}


	return 0;
}
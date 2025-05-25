#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
char s[maxn];
stack<char>q;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        int len=strlen(s),pos=0,cnt=0;
        while(pos<len&&s[pos]=='B')pos++;
        for(int i=0;i<len;i++){
            if(s[i]=='B'){
               if(q.empty())cnt++;
               else q.pop(); 
            }
            if(s[i]=='A')q.push('A');
        }
        cnt%=2;
        while(!q.empty()){
            q.pop();cnt++;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
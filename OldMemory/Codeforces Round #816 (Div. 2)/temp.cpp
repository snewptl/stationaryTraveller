#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxn=2e5+5;
const double eps=1e-10;
char res[10];
int sz=25;
bool add(int x){
    printf("+ %d\n",x);
    fflush(stdout);
    scanf("%s",res);
    return res[0]=='Y';
}
bool del(int x){
    printf("- %d\n",x);
    fflush(stdout);
    scanf("%s",res);
    return res[0]=='Y';
}
bool query(int x){
    if(add(x))return true;
    else {
        del(x);
        return false;
    }
}
int main(){
    int T=1;scanf("%d",&T);
    while(T--){
        for(int i=1;i<=sz;i++){
            add(i);
        }
        for(int j=1;j<=20;j++){
            int cur=j*sz+1;
            if(query(cur)){
                for(int i=1;i<=sz;i++){
                    if(!del(i)){
                        printf("! %d\n",cur-i);
                        fflush(stdout);
                        scanf("%s",res);
                        break;
                    }
                }
                break;
            }
        }
    }

    return 0;
}
#include<bitsdc++.h>
using namespace std;
inline void read(int &x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
}
const int maxk=21,maxs=1<<20|7;
map<int,int> mp,id;
int n,tot,ct,fat[maxk],fr[maxk],se[maxk],bin[21],afr[maxk],ase[maxk];
__int128_t dp[maxs];
char s[2000];
int islow(char c) {return 'a'<=c&&c<='z'&&c!='n';}
int find(int x) {return x==fat[x]?x:fat[x]=find(fat[x]);}
__int128_t gcd(__int128_t a,__int128_t b) {return !b?a:gcd(b,a%b);}
void out(__int128_t x)
{
    if(x) 
    {
        out(x/10);
        putchar(x%10+'0');
    }
}
void print(__int128_t x)
{ 
    if(!x) putchar('0');
    else out(x);
}
int main()
{
    freopen("fygon20.in","r",stdin);
    freopen("fygon20.out","w",stdout);
    for(int i=bin[0]=1;i<=20;++i) bin[i]=bin[i-1]<<1;
    read(n);
    for(int i=1;i<n;++i)
    {
        scanf("%[^\n]",s+1);
        getchar();
        int len=strlen(s+1),p=0;
        for(int j=2;j<=len;++j)
        {
            if(s[j-1]==' '&&islow(s[j])&&s[j+1]==' ')
            {
                if(!mp[s[j]]) mp[s[j]]=++tot;
                p=mp[s[j]];
            //    cout<<s[j]<<" "<<endl;
            }
            else if(s[j-1]=='('&&islow(s[j])&&s[j+1]==',')
            {
                fr[p]|=bin[mp[s[j]]-1];
                se[mp[s[j]]]|=bin[p-1];
          //      cout<<p<<" "<<mp[s[j]]<<" fr\n";
            }
            else if(s[j-1]==' '&&islow(s[j])&&s[j+1]==')')
            {
                se[p]|=bin[mp[s[j]]-1];
                fr[mp[s[j]]]|=bin[p-1];
                //cout<<p<<" "<<mp[s[j]]<<" se\n";
            }
        }
        //puts("");
    }
    scanf("%[^\n]",s+1);getchar();
    for(int i=1;i<=tot;++i) fat[i]=i;
    for(int tim=1;tim<=tot;++tim)
        for(int i=1;i<=tot;++i)
            for(int j=1;j<=tot;++j)
                if(fr[i]&bin[j-1])
                    fr[i]|=fr[j];
    for(int i=1;i<=tot;++i)
        for(int j=1;j<=tot;++j)
            if((fr[i]&bin[j-1])&&(fr[j]&bin[i-1]))
            {
                fat[find(i)]=find(j);
                //cout<<i<<"="<<j<<endl;
            }
    for(int i=1;i<=tot;++i) if(find(i)==i) id[i]=++ct;
    for(int i=1;i<=tot;++i)
        for(int j=1;j<=tot;++j)
            if(find(i)!=find(j)&&(fr[i]&bin[j-1]))
            {
                afr[id[find(i)]]|=bin[id[find(j)]-1];
                ase[id[find(j)]]|=bin[id[find(i)]-1];
                //cout<<i<<":"<<j<<endl;
            }
    //for(int i=1;i<=ct;++i) cout<<afr[i]<<" "<<ase[i]<<endl;
    const int mx=(1<<ct)-1;
    dp[0]=1;
    for(int s=0;s<mx;++s)
        if(dp[s])
        {
            //cout<<s<<":";print(dp[s]);puts("{}");
            for(int i=1;i<=ct;++i)
                if(!(s&bin[i-1])&&((s&afr[i])==afr[i])&&((s&ase[i])==0))
                    dp[s|bin[i-1]]+=dp[s];
        }
    __int128_t U=dp[mx],D=1,G;
    //print(U);puts("{}");
    for(int i=1;i<=ct;++i) D*=i;
    G=gcd(U,D);
    U/=G,D/=G;
    cout<<ct<<" ";print(U);putchar('/');print(D);
    return 0;
}
/*
4
for i in range(1, n):
    for j in range(1, i):
        for k in range(j, n):
            lag
*/

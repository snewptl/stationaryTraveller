            ll x=a*d,y=b*c;
            ll cd=gcd(x,y);
            x/=cd,y/=cd;
            if(x==1&&y==1)puts("0");
            else if(x!=1&&y!=1)puts("2");
            else puts("1");
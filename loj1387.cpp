using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

int main()
{
    long long int T,n,C,Case=1,sum,i;
    char s[100];

    scanf("%lld",&T);

    while(T--)
    {
        scanf("%lld",&C);
        sum = 0;

        printf("Case %d:\n",Case++);
        for(i=1;i<=C;i++)
        {
             scanf("%s",&s);

             if(s[0]=='d')
             {
                 scanf("%lld",&n);
                 sum+=n;
             }
             else
             {
                 printf("%lld\n",sum);
             }

        }
    }

    return 0;
}

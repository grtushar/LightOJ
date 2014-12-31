using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
    long long int T,n,m,ans,Case=1;

    scanf("%lld",&T);

    while(T--)
    {
        scanf("%lld%lld",&n,&m);

        ans = (m*m)*(n/(m*2));


        printf("Case %lld: %lld\n",Case++,ans);
    }

    return 0;
}

/*sum = 0;
        inc = m*m;
        flag = 1;
        temp = (m*(m+1))/2;
        con = n/m;

        for(k=0,i=temp;k<con;k++,i+=inc)
        {
            if(flag)
            {
                sum-=i;
                flag=0;
            }
            else
            {
                sum+=i;
                flag=1;
            }

        }*/


/* flag=1;
        sum=0;
        for(i=1;i<=n;i++)
        {
            if(i%m&&flag)
            {
                sum-=i;
            }
            else
            {
                if(flag==1)
                {
                    sum-=i;
                    flag=0;
                }
                else
                {
                    sum+=i;
                    if(i%m==0)
                        flag=1;
                }
            }
        }*/

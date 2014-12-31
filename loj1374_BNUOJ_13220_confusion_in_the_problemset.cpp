using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

int count[1000010];

int main()
{
    long long int arr[10010];
    int T,n,Case=1,i,flag;
    scanf("%d",&T);

    while(T--)
    {

        memset(count,0,sizeof(count));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
            count[arr[i]]++;
        }
        flag=1;

        for(i=0;i<n;i++)
        {
            if(count[i]>0)
            {
                count[i]--;
            }
            else if(count[n-1-i]>0)
            {
                count[n-1-i]--;
            }
            else
            {
                flag=0;
            }
        }

        if(flag)
            printf("Case %d: yes\n",Case++);
        else
            printf("Case %d: no\n",Case++);

    }

    return 0;
}

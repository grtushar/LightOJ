using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

int main()
{
    long long int arr[100010],i,temp,n,ans,k,index;
    int T,Case=1;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%lld",&n);
        arr[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
            temp=arr[i]-arr[i-1];
            if(i==1)
                k=arr[i];

            if(i>1&&k==temp)
                k++;
            if(k<temp)
                k=temp;

        }

        printf("Case %d: %lld\n",Case++,k);
    }

    return 0;
}

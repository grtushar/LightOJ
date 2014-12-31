using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define n 10000000+5

bool prime[n+100];

long long int arr[664599],k,i,j;

void primeFIND()
{

    k=0;

    //memset(prime , 0 , sizeof prime);

    prime[0]=prime[1]=1;

    for(i=2;i<=n;i++)
    {
        if(!prime[i])
        {
            for(j=i*i;j<=n;j=j+i)
                prime[j]=1;
            arr[k++]=i;
        }
    }

}

int main()
{
    long long int T,Case=1,p;
    scanf("%lld",&T);

    primeFIND();

    while(T--)
    {
        int count = 0;
        scanf("%lld",&p);
        for(int m=0;arr[m]<=p/2;m++)
        {
            //cout<<arr[m]<<" "<<prime[p-arr[m]]<<" "<<arr[m]<<endl;
            if(prime[p-arr[m]]==0)
                count++;
        }

        cout<<"Case "<<Case++<<": "<<count<<endl;
    }

    return 0;
}

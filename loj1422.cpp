using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

#define min(a,b) ((a<b)?(a):(b))

int dp[100+5][100+5];
int arr[100+5];

int solve(int i, int j)
{
        if(i==j)
                return 1;
        if(i>j)
                return 0;

        if(dp[i][j]!=-1)
                return dp[i][j];

        int r1=solve(i+1,j),r2=0;
        int temp=i+1;

        for(int k=i+1;k<=j;k++)
        {
                if(arr[i]==arr[k]){
                        r2+=solve(temp,k-1);
                        temp=k+1;
                }
        }

        return dp[i][j]=min(r1,r2);
}

int main()
{
        int t,n,i,Case=1;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d",&n);

                for(i=0;i<n;i++)
                        scanf("%d",&arr[i]);

                memset(dp,-1,sizeof(dp));

                printf("Case %d: %d\n",Case++,solve(0,n-1));
        }

        return 0;
}

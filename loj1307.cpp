using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>

typedef long long int ll_d;

int main()
{
        ll_d t,n,Case=1,i,k,j,count,x;
        scanf("%lld",&t);
        vector<ll_d>v;

        while(t--)
        {
                scanf("%lld",&n);
                v.clear();

                for(i=0;i<n;i++)
                {
                        scanf("%lld",&x);
                        v.push_back(x);
                }

                sort(v.begin(),v.end());

                k=n-1;
                count=0;

                for(i=0;i<n-2;i++)
                {
                        for(j=i+1;j<n-1;j++)
                        {
                                count+=(lower_bound(v.begin()+j+1,v.end(),v[i]+v[j])-(v.begin()+1+j));

                        }
                }

                printf("Case %lld: %lld\n",Case++,count);
        }

        return 0;
}


  //count+=(lower_bound(arr+j,arr+n,arr[i]+arr[j])-j);
                                /*
                                for(k=j+1;k<n;k++)
                                {
                                        if(arr[i]+arr[j]>arr[k])
                                                count++;
                                        else
                                                break;
                                }*/


  /* while(k>1)
                {
                        for(i=0;i<k-2;i++)
                        {
                                for(j=i+1;j<k-1;j++)
                                {
                                        if(arr[i]+arr[j]>arr[k])
                                        {
                                                count++;
                                        }
                                        else
                                        {
                                              //  flag=1;
                                                break;
                                        }

                                }
                        }
                        k--;
                }*/



/*ll_d binary(ll_d low,ll_d high,ll_d x)
{
        ll_d count=0,ini=low,mid;
        while(low<high)
        {
                mid=(low+high)/2;

                if(x>arr[mid])
                {
                       / if(mid-1>=0&&arr[mid-1]<x)
                                return mid-1;/
                        low=mid+1;
                }
                else if(x<=arr[mid])
                {
                        //if(mid+1<n&&arr[mid+1]>x)

                        high=mid-1;
                }
        }
        return mid-ini+1;
     /*   if(arr[mid]>x)
                return mid-ini+1;
        return mid-ini;/
}*/

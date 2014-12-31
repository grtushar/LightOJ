using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>

#define sz 50000+10
typedef long long int ll_d;

vector<ll_d>graph[sz];

void bfs()
{

}

int main()
{
        ll_d n,t,x,u,v,i,start,finish;
        scanf("%lld",&t);

        while(t--)
        {
                scanf("%lld",&n);

                for(i=0;i<n;i++)
                {
                        scanf("%lld",&x);
                        if(i==0)
                        {
                                u=x;
                                start=x;
                        }
                        else
                        {
                                graph[u].push_back(x);
                                graph[x].push_back(u);
                                u=x;
                        }

                        if(i==n-1)
                                finish=x;

                }
        }
}

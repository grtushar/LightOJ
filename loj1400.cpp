using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

int main()
{
    int t,n;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0;i<2n;i++)
        {
            scanf("%d",&x);
            for(j=0;j<n-1;j++)
            {
                scanf("%d",&fav)
                graph[x].push_back(fav);
            }
            if(i<n)
                Q.push(x);
        }

        while(!Q.empty())
        {
            for(j=0;j<graph[i].size();i++)
            {
                u=graph[i][j];
                if(pair[u]==0)
                {
                    pair[u]=i;
                    break;
                }
                else
                {
                    if(check(u,i))
                    {
                        pair[u]=
                    }
                }
            }
        }
    }
}

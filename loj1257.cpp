using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>

#define sz 30000+10
#define max(a,b) ((a>b)?(a):(b))

struct info {
    int node,cost;
    info(int a,int b)
    {
        node=a;
        cost=b;
    }
    /*bool operator < ( const graph& p ) const {
        return cost > p.cost;
    }*/
};
vector<info>graph[sz];
long long cost1[sz],cost2[sz],cost3[sz];
int n,mxidx,mxv;
bool visited[sz];

void bfs(int s, int flag)
{
        queue<int>Q;
        if(flag==1) cost1[s]=0;
        else if(flag==2) cost2[s]=0;
        else cost3[s]=0;
        for(int i=0;i<=n;i++)
                visited[i]=false;
        visited[s]=true;
        Q.push(s);
        mxidx=s;
        mxv=0;

        while(!Q.empty())
        {
                int u = Q.front();
                Q.pop();

                for(int i=0;i<graph[u].size();i++)
                {
                        int v = graph[u][i].node;
                        if(visited[v]==false)
                        {
                                visited[v]=true;
                                if(flag==1) {
                                        cost1[v]=cost1[u]+graph[u][i].cost;
                                        if(cost1[v]>mxv) { mxidx=v; mxv=cost1[v]; }
                                }
                                else if(flag==2) {
                                        cost2[v]=cost2[u]+graph[u][i].cost;
                                        if(cost2[v]>mxv) { mxidx=v; mxv=cost2[v]; }
                                }
                                else {
                                        cost3[v]=cost3[u]+graph[u][i].cost;
                                        if(cost3[v]>mxv) { mxidx=v; mxv=cost3[v]; }
                                }
                                Q.push(v);
                        }
                }
        }
}

int main()
{
        int t,u,v,w,i,Case=1;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d",&n);

                for(i=0;i<n-1;i++)
                {
                        scanf("%d%d%d",&u,&v,&w);
                        graph[u].push_back(info(v,w));
                        graph[v].push_back(info(u,w));
                }

               bfs(0,1);
               bfs(mxidx,2);
               bfs(mxidx,3);

               printf("Case %d:\n",Case++);
               for(i=0;i<n;i++){
                        printf("%lld\n",max(max(cost1[i],cost2[i]),cost3[i]));
                        graph[i].clear();
               }
        }

        return 0;
}

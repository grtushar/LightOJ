using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>

#define sz 1000+10
#define min(a,b) ((a<b)?(a):(b))

vector<int>graph[sz],n;
bool visited[sz];
int taka[sz],p_taka,count;

bool bfs(int s)
{
        int i;
        //memset(visited,false,sizeof(visited));
        queue<int>Q;
        Q.push(s);
        count=1;
        p_taka=taka[s];
        visited[s]=true;

        while(!Q.empty())
        {
                //cout<<"enter"<<endl;
                int u=Q.front();
                Q.pop();

                for(i=0;i<graph[u].size();i++)
                {
                        if(visited[graph[u][i]]==false)
                        {
                                visited[graph[u][i]]=true;
                                count+=1;
                                p_taka+=taka[graph[u][i]];
                                Q.push(graph[u][i]);
                        }
                }
        }

        if(p_taka%count)
                return false;
        return true;
}

int main()
{
        int t,n,m,u,v,i,Case=1,check;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&n,&m);

                for(i=1;i<=n;i++)
                {
                        scanf("%d",&taka[i]);

                }

                for(i=0;i<m;i++)
                {
                        scanf("%d%d",&u,&v);
                        graph[u].push_back(v);
                        graph[v].push_back(u);
                }

                memset(visited,false,sizeof(visited));

                bool flag;

                for(i=1;i<=n;i++)
                {
                        if(visited[i]==false)
                        {
                                flag=bfs(i);
                                if(flag==false)
                                        break;
                                else
                                {
                                        if(i==1)
                                        {
                                                check=p_taka/count;
                                        }
                                        else
                                        {
                                                if(check!=p_taka/count)
                                                {
                                                        flag=false;
                                                        break;
                                                }
                                        }
                                }
                        }
                }

                if(flag)
                {
                        printf("Case %d: Yes\n",Case++);
                }
                else
                {
                        printf("Case %d: No\n",Case++);
                }

                for(i=1;i<=n;i++)
                        graph[i].clear();


        }

        return 0;
}

//  sum+=taka[i];
                       /*  if(i==1)
                         {
                                 s=i;
                                 mini=taka[i];
                         }
                         else
                         {
                                 if(mini>taka[i])
                                 {
                                         mini=taka[i];
                                         s=i;
                                 }
                         }*/

                          /* if(sum%n)
                {
                        printf("Case %d: No\n",Case++);
                }
                else
                {
                       flag=bfs(s);
                }*/

using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<math.h>
#include<vector>

#define N 10000+10
#define ll unsigned long long int
#define MOD 4294967296

bool prime[N];//,vis[10000000+10];
int primes[1300],k=0;
int m[1000000+10],sz;
long long ans[1000000+10];
ll store;

void sieve()
{
        int i,j,sq=sqrt(N);
        prime[0]=prime[1]=true;

        //primes.push_back(2);
        primes[k++]=2;
        int cnt=1;
        for(i=4;i<N;i+=2)
                prime[i]=true;

        for(i=3;i<=sq;i+=2)
        {
                if(prime[i]==false)
                {
                        cnt++;
                        //primes.push_back(i);
                        primes[k++]=i;
                        for(j=i*i;j<N;j+=2*i)
                                prime[j]=true;
                }
        }

        while(i<N)
        {
                if(prime[i]==false)
                        primes[k++]=i;//primes.push_back(i);
                i+=2;
        }
}

void counting_divisor(ll n)
{
        ll temp=n;
        int j,sq=sqrt(n),cnt;
        //store=ans[temp];
        for(j=0;j<sz&&primes[j]<=sq;j++)
        {
                //cout<<"check"<<endl;
                if(n%primes[j]==0)
                {
                        cnt=0;
                        while(n%primes[j]==0)
                        {
                                n/=primes[j];
                                cnt++;
                        }

                        if(m[primes[j]]<cnt)
                        {
                                ans[temp]=ans[temp]*(cnt-m[primes[j]])*primes[j];
                                //store=store*(cnt-m[primes[j]])*primes[j];
                                //ans[temp]=store;
                                m[primes[j]]+=cnt-m[primes[j]];
                                /*while(ans[temp] % 10 == 0)
                                        ans[temp] /= 10;
                                ans[temp] %= 10000000;*/
                                ans[temp]%=MOD;
                        }
                }

                if(n==1) break;
        }

        if(n>1)
        {
                if(m[n]<1)
                {
                        ans[temp]*=n;
                       // store=store*n;
                        //ans[temp]=store;
                        m[n]++;
                        //while(ans[temp] % 10 == 0)
                                //ans[temp] /= 10;
                                //if(ans[temp]>10000000)
                        //ans[temp] %= 10000000;
                        ans[temp]%=MOD;
                }
        }
        //ans[temp]=store;
}

/*ll counting_divisor(ll n)
{
        ll temp=n;
        int j,sq=sqrt(n),cnt;
        for(j=0;j<sz&&primes[j]<=sq;j++)
        {
                if(n%primes[j]==0)
                {
                        cnt=0;
                        while(n%primes[j]==0)
                        {
                                n/=primes[j];
                                cnt++;
                        }

                        if(m[primes[j]]<cnt)
                        {
                                ans[temp]=ans[temp]*(cnt-m[primes[j]])*primes[j];
                                m[primes[j]]+=cnt-m[primes[j]];
                                ans[temp]%=MOD;
                        }
                }

                if(n==1) break;
        }

        if(n>1)
        {
                if(m[n]<1)
                {
                        ans[temp]*=n;
                        m[n]++;
                        ans[temp]%=MOD;
                }
        }
}
*/

int main()
{
        sieve(); sz = k;//primes.size();
        //cout<<k<<"done1"<<endl;

        long long i,n;
        int t,Case=1;

        ans[0]=0; ans[1]=1;
        for(i=2;i<=1000000;i++){
                ans[i]=ans[i-1];
                counting_divisor(i);
                //cout<<i<<endl;
        }
        //cout<<"done :/"<<endl;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%lld",&n);
                if(n<=1000000)
                        printf("Case %d: %lld\n",Case++,ans[n]);
               /* else if(vis[n])
                        printf("Case %d: %lld\n",Case++,ans[n]);*/
                else
                {
                        temp=ans[1000000];
                        for(i=1000001;i<=n;i++)
                        {
                                store
                                counting_divisor2(i);
                                //vis[i]=true;
                        }
                        printf("Case %d: %lld\n",Case++,ans[n]);
                }
        }

        return 0;
}


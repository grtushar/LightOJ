using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
        int t,Case=1,n,i;
        long long int x,XOR;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d",&n);

                XOR=0;
                for(i=0;i<n;i++){
                        scanf("%lld",&x);
                        XOR^=x;
                }

                if(n==1&&x==1) printf("Case %d: Alice\n",Case++);
                else if(XOR) printf("Case %d: Alice\n",Case++);
                else printf("Case %d: Bob\n",Case++);
        }

        return 0;
}

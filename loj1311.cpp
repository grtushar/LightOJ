using namespace std;

#include<iostream>
#include<math.h>
#include<cstdio>

#define max(a,b) ((a>b)?(a):(b))

int main()
{
        int t,Case=1;
        double v1,v2,v3,a1,a2;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2);
                printf("Case %d: %.10lf %.10lf\n",Case++,((v1*v1)/(2*a1))+((v2*v2)/(2*a2)),max(v1/a1,v2/a2)*v3);
        }

        return 0;
}

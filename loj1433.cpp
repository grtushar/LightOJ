using namespace std;

#include<iostream>
#include<cmath>
#include<cstdio>

#define pi (2*(acos(0.0)))

double finding_length(double x1,double y1,double x2,double y2)
{
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}

int main()
{
    double Ox, Oy, Ax, Ay, Bx, By,OA,OB,AB,angle;
    int T,Case=1;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&Ox, &Oy, &Ax, &Ay, &Bx, &By);

        OA = finding_length(Ox,Oy,Ax,Ay);
        OB = finding_length(Ox,Oy,Bx,By);
        AB = finding_length(Ax,Ay,Bx,By);

        angle = acos(((OA*OA)+(OB*OB)-(AB*AB))/(2*OA*OB));

        printf("Case %d: %.8lf\n",Case++,(OA*angle));
    }

    return 0;
}

/*using namespace std;

#include<iostream>
#include<cmath>
#include<cstdio>*/

#include<stdio.h>
#include<math.h>

#define absolute(x) ((x<0)?(-x):(x))

double length_of_line(int x1,int y1,int x2,int y2)
{
    return sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
}

double traingle_area(double a,double b,double c)
{
    double s=(a+b+c)/2;
    return sqrt((s*(s-a)*(s-b)*(s-c)));
}

int main()
{
    int Ax, Ay, Bx, By, Cx, Cy,T,Dx,Dy,Case=1;
    double ab,bc,ca,abc,area;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d%d%d%d%d",&Ax,&Ay,&Bx,&By,&Cx,&Cy);

        Dx = Cx+(Ax-Bx);
        Dy = Cy+(Ay-By);

        ab = length_of_line(Ax,Ay,Bx,By);
        bc = length_of_line(Bx,By,Cx,Cy);
        ca = length_of_line(Cx,Cy,Ax,Ay);

        abc = traingle_area(ab,bc,ca);
        area = 2*abc;

        printf("Case %d: %d %d %.0lf\n",Case++,Dx,Dy,area);
    }

    return 0;
}

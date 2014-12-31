//{ Template

//{ C-headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ C++-headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;
//}

//}
//{ Floating-points
#define EPS DBL_EPSILON
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2 * acos (0.0)
//}
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define INF 1<<29
#define ll long long
#define db double
#define pii pair<int ,int >
#define NL puts("")
#define G getchar()
//}

//compute b^p
ll Pow(ll  b,ll  p){
    ll  ret = 1;
    while(p){
        if(p&1) ret *= b ;
        p >>= (1ll) , b *= b ;
    }
    return ret ;
}

//compute b^p%m
ll BigMod(ll  b,ll  p ,ll  m ){
     ll  ret = 1 ;
     while(p)  {
        if(p&1) ret = (ret * b ) % m ;
        p >>= (1ll) , b = (b*b)%m ;
     }
    return ret ;
}

//compute gcd of (a,b)
ll GCD(ll a , ll b){
    while(b) b ^=  a ^= b ^= a %= b ;
    return a;
}

//compute lcm of (a,b)
ll LCM(ll a , ll b) {
     return (a / GCD(a,b)*b);
}


int main () {

        int t, m, date1, date2,i,Case=1;
        ll year1, year2, ans;
        string month1, sdate1, month2, sdate2;
        scanf("%d",&t);

        while(t--)
        {
                cin>>month1>>sdate1>>year1;
                cin>>month2>>sdate2>>year2;

                m = 1;
                date1 = date2 = 0;
                for(i=0;i<sdate1.length()-1;i++)
                {
                        date1 = date1*m+(sdate1[i]-48);
                        m*=10;
                }

                m = 1;
                for(i=0;i<sdate2.length()-1;i++)
                {
                        date2 = date2*m+(sdate2[i]-48);
                        m*=10;
                }

                if(month1!="January"&&month1!="February")
                {
                        year1++;
                }

                if(month2=="January"||(month2=="February"&&date2<29))
                {
                        year2--;
                }

                while(year1%4&&year1+1<=year2) year1++;

                ans = 0;

                //cout<<year1<<"  "<<year2<<endl;

                if(year1%4==0)
                {
                        while(year1%400&&year1<=year2)
                        {
                                if(year1%100) ans++;
                                year1+=4;
                        }

                        if(year1%400==0)
                        {
                                ans++;

                                ans+=(year2/4-year1/4);
                                ans-=(year2/100-year1/100);
                                ans+=(year2/400-year1/400);
                        }
                }




                printf("Case %d: %lld\n",Case++,ans);
        }
        return 0;
}

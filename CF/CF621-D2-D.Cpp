/*
the idea of the problem is to multiply by log two both sides and i can already calculate x^y for x and y = 200 by long double
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define   angle(n)      atan2((n.imag()),(n.real()))
#define   vec(a,b)       ((b)-(a))
#define   length(a)      hypot( (a.imag()),(a.real()) )
#define   normalize(a)      (a)/(length(a))
#define    dp(a,b)          (((conj(a))*(b)).real())
#define    cp(a,b)          (((conj(a))*(b)).imag())
#define    lengthsqrt(a)       dp(a,a)
#define    rotate0( a,ang)    ((a)*exp( point(0,ang) ))
#define    rotateA(about,p,ang)   (rotate0(vec(about,p),ang)+about)
#define    lcm(a,b)                ((a*b)/(__gcd(a,b)))
#define    reflection0(m,v)         (conj((v)/(m))*(m))
#define     reflectionA(m,v,p0)     (conj( (vec(p0,v))/(vec(p0,m)) ) * (vec(p0,m)) ) + p0
#define     same(p1,p2)               ( dp(  vec(p1,p2),vec(p1,p2)) < eps )
#define     point                    complex<double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
string ans[13]={"x^y^z","x^z^y","(x^y)^z","(x^z)^y","y^x^z","y^z^x","(y^x)^z","(y^z)^x","z^x^y","z^y^x","(z^x)^y","(z^y)^x"};
long double x,y,z;
bool comp(int i,int j)
{
     long double x1,x2,y1,y2,z1,z2;
    if(ans[i][0]!='(')
    {
        if(ans[i][0]=='x')
        x1=x;
        else if(ans[i][0]=='y')
        x1=y;
        else
          x1=z;

        if(ans[i][2]=='x')
        y1=x;
        else if(ans[i][2]=='y')
        y1=y;
        else
          y1=z;

        if(ans[i][4]=='x')
        z1=x;
        else if(ans[i][4]=='y')
        z1=y;
        else
          z1=z;
    }
    else if(ans[i][0]=='(')
    {
        if(ans[i][1]=='x')
        x1=x;
        else if(ans[i][1]=='y')
        x1=y;
        else
          x1=z;

        if(ans[i][3]=='x')
        y1=x;
        else if(ans[i][3]=='y')
        y1=y;
        else
          y1=z;

        if(ans[i][6]=='x')
        z1=x;
        else if(ans[i][6]=='y')
        z1=y;
        else
          z1=z;
    }

    ///////////////////////

     if(ans[j][0]!='(')
    {
        if(ans[j][0]=='x')
        x2=x;
        else if(ans[j][0]=='y')
        x2=y;
        else
          x2=z;

        if(ans[j][2]=='x')
        y2=x;
        else if(ans[j][2]=='y')
        y2=y;
        else
          y2=z;

        if(ans[j][4]=='x')
        z2=x;
        else if(ans[j][4]=='y')
        z2=y;
        else
          z2=z;
    }
    else if(ans[j][0]=='(')
    {

        if(ans[j][1]=='x')
        x2=x;
        else if(ans[j][1]=='y')
        x2=y;
        else
          x2=z;

        if(ans[j][3]=='x')
        y2=x;
        else if(ans[j][3]=='y')
        y2=y;
        else
          y2=z;

        if(ans[j][6]=='x')
        z2=x;
        else if(ans[j][6]=='y')
        z2=y;
        else
          z2=z;
    }


    if(ans[i][0]=='('&&ans[j][0]=='(')
    {
        if(dcmp(z1*log(powl(x1,y1)),z2*log(powl(x2,y2)))!=-1)
            return 1;

    }

    if(ans[i][0]=='('&&ans[j][0]!='(')
    {
        if(dcmp(z1*log(powl(x1,y1)),powl(y2,z2)*log(x2))!=-1)
            return 1;
    }
    if(ans[i][0]!='('&&ans[j][0]=='(')
    {
        if(dcmp(powl(y1,z1)*log(x1),z2*log(powl(x2,y2)))!=-1)
        {

            return 1;
        }

    }
    if(ans[i][0]!='('&&ans[j][0]!='(')
    {
        if(dcmp(powl(y1,z1)*log(x1),powl(y2,z2)*log(x2))!=-1)
            return 1;

    }
 return 0;
}
int main()
{

    cin>>x>>y>>z;

    for(int i=0;i<12;i++)
    {
        int fl=0;
        for(int j=0;j<12;j++)
          if(!comp(i,j))
            fl=1;

        if(!fl)
        {
            cout<<ans[i]<<endl;
            return 0;
        }
    }
}

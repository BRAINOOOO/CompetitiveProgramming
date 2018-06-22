
// ICPC champion is here
#include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<map>
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
#define     point                    complex<long double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
ll X,Y,x,y,fl;
string st;
ll sx,sy,GX,GY;
int main()
{

    cin>>x>>y>>st;
    if(!x&&!y)
    {
        cout<<"Yes\n";
         return 0;
    }

    GX=0,GY=0;
    for(int i=0;i<sz(st);i++)
    {


        if(st[i]=='U')
            GY+=1;
        if(st[i]=='R')
            GX+=1;
        if(st[i]=='L')
            GX-=1;
        if(st[i]=='D')
            GY-=1;


    }
    X=0,Y=0;
    for(int i=0;i<sz(st);i++)
    {

        if(st[i]=='U')
            Y+=1;
        if(st[i]=='R')
            X+=1;
        if(st[i]=='L')
            X-=1;
        if(st[i]=='D')
            Y-=1;

       sx=x-X;
       sy=y-Y;
       if(sx==0&&sy==0)
       {
           cout<<"Yes\n";
           return 0;
       }

     bool ok1= (GX==0? sx==0 : (sx%GX==0&&sx/GX>=0));
     bool ok2= (GY==0? sy==0 : (sy%GY==0&&sy/GY>=0));
       if(ok1&&ok2&&sx*GY==GX*sy)
       {
           cout<<"Yes\n";
           return 0;
       }

    }

 cout<<"No\n";
}




/*
explanation : here the idea is i will work for each point separately here i want to know
the first point i will intersect with it in a segment so the water will move directly in a
strightline cutting all the segments below it at a certain point i need the the point
of intersection with the max y-axis to be the first point to cut then see whether it
goes up or down and go with it to a new point from it you will do the same till there is 
no segments intersect with the point so here we reach the finial X-axis.
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
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int ccw(point p0,point p1,point p2)
{
    point v1=vec(p0,p1),v2=vec(p0,p2);
    if(cp(v1,v2)>eps)
        return 1;
    if(cp(v1,v2)<-eps)
        return -1;
    if(v1.real()*v2.real()<-eps|| v1.imag()*v2.imag()<-eps)
        return -1;
    if(norm(v1)< norm(v2)-eps)
        return 1;
    return 0;
}
bool isintersect(point p1,point p2,point p3,point p4)
{
    bool x=(p1==p2),y=(p3==p4);
    if(x&&y)
    return p1==p3;
    if(x)
        return  ccw(p3,p4,p1)==0 ;
    if(y)
     return ccw(p1,p2,p3)==0 ;
    return ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0  &&  ccw(p3,p4,p1)*ccw(p3,p4,p2) <= 0;
}
pair<bool,point> check(point a,point b,point c,point d)
{
    point inter;
    if(!isintersect(a,b,c,d))
        return mp(0,a);
    double d1=cp(a-b,d-c),d2=cp(a-c,d-c),d3=cp(a-b,a-c);
    double t1=d2/d1,t2=d3/d1;
    inter= a+(b-a)*t1;
    return mp(1,inter);
}
int main()
{
    int t,fl=0;
    cin>>t;

    while(t--)
    {
       if(fl)
       cout<<endl;
       fl=1;
        vector< pair< pair<int,int>,pair<int,int> > > v;
       int n;
       cin>>n;
       int x1,x2,y1,y2;
       for(int i=0;i<n;i++)
       {
           cin>>x1>>y1>>x2>>y2;
           v.pb(mp(mp(x1,y1),mp(x2,y2)));
       }
     int m;
     cin>>m;
     int x,y,fx,fy;
     for(int i=0;i<m;i++)
     {
          cin>>x>>y;
          fx=x;
          fy=y;
        while(1)
        {
            point a,b;
            a.real(fx);a.imag(fy);
            b.real(fx);b.imag(0);
           double mx=-1;
           int id;
           for(int j=0;j<n;j++)
           {
             x1=v[j].first.first;
             y1=v[j].first.second;
             x2=v[j].second.first;
             y2=v[j].second.second;
              point c,d;
              c.real(x1);c.imag(y1);
              d.real(x2);d.imag(y2);
              if(a==c||a==d)
                continue;
             pair<bool, point> t= check(a,b,c,d);
             if(t.first==0)
                continue;
             point I=t.second;
              if(I.imag()>mx)
              {
                  mx=I.imag();
                  id=j;
              }
           }
           if(mx==-1)
           {
               cout<<fx<<endl;
               break;
           }
             x1=v[id].first.first;
             y1=v[id].first.second;
             x2=v[id].second.first;
             y2=v[id].second.second;
             if(x1>x2)
             {
                 swap(x1,x2);
                 swap(y1,y2);
             }
            if(y2>y1)
            {
                fx=x1;
                fy=y1;
            }
            else
            {
                fx=x2;
                fy=y2;
            }
        }
     }
    }
}

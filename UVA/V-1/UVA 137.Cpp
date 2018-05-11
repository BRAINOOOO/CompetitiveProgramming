// ICPC Champion is here

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
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
vector<point> p1,p2;

double PolygonArea(vector<point> &p)
{

    double a=0.0;

    for(int i=0;i<sz(p);i++)
    {
        point cur= p[i]; point nxt=p[(i+1)%sz(p)];
        a+= cp(cur,nxt);
    }

 return fabs(a/2.0);
}



bool interseg(point a,point b,point c,point d,point &intersect)
{
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if((fabs(d1)< eps))
        return 0;

     double t1=d2/d1;  double t2=d3/d1;
    intersect=a+(b-a)*t1;

    if(t2<-eps||t2>1+eps)
        return 0;

    return 1;
}
vector<point> polygoncut(point a,point b,vector<point> &p)
{
    vector<point> nw;

    for(int i=0;i<sz(p);i++)
    {
        point cur=p[i]; point nxt=p[(i+1)%sz(p)];

        if(cp(b-a,cur-a)< -eps)
            nw.pb(p[i]);
        point inter;
        if(interseg(a,b,cur,nxt,inter))
            nw.pb(inter);

    }
    return nw;
}










vector<point> inter()
{

    vector<point> res;
    res=p1;

    for(int i=0;i<sz(p2);i++)
    {
        point cur=p2[i]; point nxt=p2[(i+1)%sz(p2)];

        res=polygoncut(cur,nxt,res);

    }

   return res;
}








int main()
{
    int n;
    while(cin>>n)
    {
        p1.clear();
        p2.clear();
       if(n==0)
        break;
      double x,y;
       for(int i=0;i<n;i++)
        cin>>x>>y,p1.pb(point(x,y));
       int m;
       cin>>m;
       for(int i=0;i<m;i++)
        cin>>x>>y,p2.pb(point(x,y));

      vector<point> p3= inter();
      double bet= PolygonArea(p3);
      double fir= PolygonArea(p1);
      double sec= PolygonArea(p2);

      fir-=bet;
      sec-=bet;

      fir+=sec;

     printf("%8.2f",fir);
    }
}


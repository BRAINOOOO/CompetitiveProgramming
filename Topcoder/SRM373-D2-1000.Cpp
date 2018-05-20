
// ICPC Champion is here

#include <bits/stdc++.h>
#include<iostream>
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
//#define     point                    complex<long double>
#define      PI                      acos(-1)
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
struct point
{
  int x,y;
  point(int x=0,int y=0):x(x),y(y){}

  point operator -(point &other)
  {
      return point(x-other.x,y-other.y);
  }
  inline bool operator ==(point &other)
  {
     return x==other.x&&y==other.y;
  }
};
struct rect
{
  point a,b,c,d;
  int area;
  rect(point a,point b,point c,point d,int area=0):a(a),b(b),c(c),d(d),area(area){}
};
struct seg
{
  point a,b;
  seg(point a,point b):a(a),b(b){}
};
const int N=105;
bool Cont[N];
const double EPS=1e-5;

class RectangleCrossings
{
public:
       double norm(point &v1)
       {
          return sqrt(((double)v1.x*v1.x)+((double)v1.y*v1.y));
       }

       int cross(point &v1,point &v2)
       {
           return v1.x*v2.y-v1.y*v2.x;
       }

       int ccw(point &a,point &b,point &c)
       {
          point v1=b-a;
          point v2=c-a;
          if(cross(v1,v2)>0)return 1;
          if(cross(v1,v2)<0)return -1;
          if(v1.x*v2.x < 0 || v1.y*v2.y < 0)return -1;
          if(norm(v1) < norm(v2) -eps)return 1;
          return 0;
       }
       bool InterSeg(point &a,point &b,point &c,point &d)
       {
           bool f1=(b==a),f2=(c==d);
           if(f1&&f2)return a==c;

           if(f1) return ccw(c,d,a)==0;
           if(f2)  return ccw(a,b,c)==0;

           return ccw(a,b,c)*ccw(a,b,d)<=0&&
                  ccw(c,d,a)*ccw(c,d,b)<=0;
       }
       bool contain(point &a,point &b,point &c,point &d,point &f1,point &f2)
       {
                 if((f1.x>a.x&&f1.x<b.x&&f1.y>a.y&&f1.y<d.y)||(f2.x>a.x&&f2.x<b.x&&f2.y>a.y&&f2.y<d.y))
                    return 1;
                 
                 return 0;
       }


	vector <int> countAreas(vector <string> rec, vector <string> segment)
	{
	       int n=rec.size();
	       point a,b,c,d;
	       vector<rect>r;
	       vector<seg>s;
	       memset(Cont,0,sizeof(Cont));

	       for(int i=0;i<n;i++)
           {
	           istringstream in(rec[i]);
	           in>>a.x>>a.y>>c.x>>c.y;
	           b.x=c.x,b.y=a.y;
	           d.x=a.x,d.y=c.y;
	           r.push_back(rect(a,b,c,d,((d.y-a.y)*(b.x-a.x))));
	       }

	       for(int i=0;i<segment.size();i++)
           {
	           istringstream in(segment[i]);
	           in>>a.x>>a.y>>b.x>>b.y;
	           s.push_back(seg(a,b));

	       }
	       n=r.size();
	       int  m=s.size();
	       int inter_area=0;
	       int contain_area=0;
	       // contain
            for(int i=0;i<n;i++)
            {
	          for(int j=0;j<m;j++)
	          {
	            if(contain(r[i].a,r[i].b,r[i].c,r[i].d,s[j].a,s[j].b))
                {
	                contain_area+=r[i].area;
	                Cont[i]=1;
	                break;
	            }
	          }
	       }


	       for(int i=0;i<n;i++)
          {
	          if(Cont[i])continue;
	          for(int j=0;j<m;j++)
              {
	              if(InterSeg(r[i].a,r[i].b,s[j].a,s[j].b)||InterSeg(r[i].b,r[i].c,s[j].a,s[j].b)||
	                 InterSeg(r[i].c,r[i].d,s[j].a,s[j].b)||InterSeg(r[i].d,r[i].a,s[j].a,s[j].b))
                  {

	                 inter_area+=(r[i].area);
	                 break;
	              }
	          }
	       }

	  	return vector<int>{contain_area,inter_area};

	}
};



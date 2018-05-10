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
//#define     point                    complex<double>
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
    ll x,y;
    point(int x=0,int y=0) : x(x),y(y){}
    point operator -(point &e)
    {
        return point(x-e.x,y-e.y);
    }
};
vector<point> v;
ll Cross(point a,point b)
{
    return a.x*b.y-b.x*a.y;
}
ll norml(point a)
{
    return a.x*a.x+a.y*a.y;
}
int CCW(point a, point b, point c)
{
  point v1(b - a), v2(c - a);

  int t = Cross(v1, v2);

  if (t > 0)
	return +1;
  if (t < 0)
	return -1;

  if (v1.x * v2.x < 0 || v1.y * v2.y < 0)
	return -1;

  if (norml(v1) < norml(v2) )
	return +1;

  return 0;
}














void isinside(point p0)
{

    ll wn=0;

    for(int i=0;i<sz(v);i++)
    {
        point cur=v[i]; point nxt=v[(i+1)%sz(v)];

        if(CCW(cur,nxt,p0)==0)
        {
            cout<<"EDGE\n";
            return;
        }

        if(cur.y<=p0.y)
        {
            if(nxt.y>p0.y&&Cross(nxt-cur,p0-cur)>0)
                wn++;
        }
        else
        {
            if(nxt.y<=p0.y&&Cross(nxt-cur,p0-cur)<0)
                wn--;
        }
    }
    cout<<wn<<endl;
}

int main()
{
    int n;
    cin>>n;
    int x,y;
    for(int i=0;i<n;i++)
       cin>>x>>y, v.pb(point(x,y));
     int p;
    cin>>p;
    for(int i=0;i<p;i++)
    {
        cin>>x>>y;
        isinside(point(x,y));
    }
}



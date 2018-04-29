/*
the idea is to get the diameter of the polygon and compare it with the diameter of the circle
*/


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
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
vector<pair<ll,ll> > v;


ll dist(pair<ll,ll> a,pair<ll,ll>  b)
{
    return (b.first-a.first)*(b.first-a.first) + (b.second-a.second)*(b.second-a.second);
}


int main()
{

    ll n;

    while(cin>>n)
    {

        if(n==0)
            break;
        v.clear();
       ll y,x;
       for(int i=0;i<n;i++)
       {
           cin>>x>>y;
           v.pb(mp(x,y));
       }
       double r;
       cin>>r;


     ll mx=0.0;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<n;j++)
          {


             mx=max(dist(v[i],v[j]),mx);

          }
      }
   if(dcmp(mx,r*2*r*2)!=1)
   cout<<"The polygon can be packed in the circle.\n";

    else
    cout<<"There is no way of packing that polygon.\n";
    }
}



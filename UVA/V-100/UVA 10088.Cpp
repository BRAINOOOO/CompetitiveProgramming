/*
here the idea is the apply pick's theorem but yu need 2 things
1- area of polygon  yu can get it
2- number of boundry points which is by gcd
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
vector< point > v;
ll X[100000],Y[100000];
long double Polygonarea()
{

     long double ans=0;
     for(int i=0;i<sz(v);i++)
     {
          ans+= cp(v[i],v[(i+1)%sz(v)]);
     }

     return fabsl(ans/2.0);
}










int main()
{
    ll n,x,y;
    while(cin>>n)
    {

        v.clear();

        if(!n)
            break;
       point prev;
       ll r=0;
       for(int i=0;i<n;i++)
       {
           cin>>X[i]>>Y[i];
            point p;
           p.real(X[i]); p.imag(Y[i]);
           v.pb(p);
       }

       for(int i=0;i<=n;i++)
       {
           point cur=v[(i%sz(v))];
           x=cur.real(); y=cur.imag();


           if(i!=0)
           {
               ll x1=prev.real(); ll y1=prev.imag();
               ll x2=x;     ll y2=y;

              if(y2-y1==0)
              {
                  r+= abs(x2-x1)+1;
              }
              else if(x2-x1==0)
              {
                  r+= abs(y2-y1)+1;
              }
              else
              {

                 r+=  __gcd(abs(y2-y1),abs(x2-x1));
                 r+=1;
              }

           }
           prev=cur;
       }

        r-=n;

        //cout<<r<<endl;

       double A=Polygonarea();

        cout<<fixed<<setprecision(0)<< floor(A-(r/2)+1) <<endl;
    }
}


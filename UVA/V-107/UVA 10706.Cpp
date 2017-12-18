/*
explanation : here the idea is to divide the problem, divide the sequence into the groups
then get the group where your idex include using binary search then deal with it as a new problem 
and you can get the idex inside it linearly since the max K fit in the time ( you can calculate it 
using the constrains ) where the accumulative sum is n*(n+1)/2 and it should be <=  2147483647 so 
n is approximately =6*(10^4) which it fits.

complexity : O( T*6*(10^4) )
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
ll f[65536+9];
int cntd(ll n)
{
    int k=0;
    while(n>0)
    {
        n/=10;
        k++;
    }
    return k;
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=65536;i++)
    {
        int n=cntd(i);
        f[i]=f[i-1]+n;
    }
    ll cnt=0;
   vector<ll> v;
     v.pb(0);
     for(int i=1;i<=65536;i++)
       {
           cnt+=f[i];
           v.pb(cnt);
       }
    while(t--)
    {
       int num;
       cin>>num;
     int id= upper_bound(all(v),num)-v.begin();
      if(v[id-1]==num)
        id--;
      num-=v[id-1];
    string v1="";
      for(int i=1;i<=id;i++)
      {
          string s=to_string(i);
          v1+=s;
      }
      cout<< v1[num-1] <<endl;
    }
}

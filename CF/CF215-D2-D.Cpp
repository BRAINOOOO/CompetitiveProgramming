/*
the idea is greedy
first of all if the bus won't burn so there is no need for extra buses
if it will burn i will compare between adding a bus or not 
*/


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
#define     point                    complex<long double>
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
const int X=100009;
ll t[X],T[X],cost[X],x[X];
ll inf=10000000000000000;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++)
    {
        scanf("%I64d %I64d %I64d %I64d",&t[i],&T[i],&x[i],&cost[i]);
    }
   ll ans=0;
   for(int i=0;i<n;i++)
   {

       ll lim=T[i]-t[i];

       if(m<=lim)
       {
           ans+=cost[i];
          // cout<<cost[i]<<endl;
           continue;
       }
       ll a1;

       ll rem=m-lim;
       if(lim>0)
       {

       ll bases=ceil((rem+0.0)/lim);
       a1= bases*cost[i]+cost[i];
       }
       else
        a1=inf;
       ll a2=m*x[i]+cost[i];
       //cout<<a1<<" "<<a2<<endl;
       ans+=min(a1,a2);
   }
   printf("%I64d\n",ans);
}


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
//int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int g,r;
int mem[2][2*100000+1],T;
int MOD=1e9+7,mx;






int main()
{
    scanf("%d %d",&r,&g);
    mx=-1;
    T=r+g;
    for(int i=895;i>=1;i--)
    {
        if((i*(i+1))/2<=T)
            mx=max(i,mx);
    }
    if(g>0)
   mem[0][1]=1;
   if(r>0)
   mem[0][0]=1;

   for(int lv=2;lv<=mx;lv++)
   {
       int blocks=(lv*(lv+1)/2);
       int p= !(lv&1);
       clr(mem[p],0);
       for(int gcnt=0;gcnt<=g;gcnt++)
       {

            if(blocks-gcnt<=r)
           mem[p][gcnt]=(mem[p][gcnt]+mem[!p][gcnt])%MOD;
           if(gcnt+lv<=g)
           mem[p][gcnt+lv]=(mem[p][gcnt+lv]+mem[!p][gcnt])%MOD;


       }
   }


  int ans=0;
  int p=!(mx&1);


  for(int i=0;i<=g;i++)
    ans=(ans+mem[p][i])%MOD;

  cout<<ans<<endl;

}

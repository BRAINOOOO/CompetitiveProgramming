/*
explanation : here we want the min number pebbles remain so we wnt to maxmize on the number of pebbles removed 
at each move we can remove one pebble so i will try all the possible moves but i will need to mem a vector of pebbles
as the len of the pebbles are only 12 so we could express this vector as a mask.

complexity : n*2^n
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
int mem[(1<<12)-1+9];
int fun(int msk)
{
    if(mem[msk]!=-1)
        return mem[msk];
    int ans=0;
    for(int i=0;i<12;i++)
    {
        if(i+2<12&&getBit(msk,i)&&getBit(msk,i+1)&&!getBit(msk,i+2))
        {
            int tmsk=setBit0(msk,i);
            tmsk=setBit0(tmsk,i+1);
            tmsk=setBit1(tmsk,i+2);
            ans=max(ans, 1 + fun(tmsk));

        }
        if(i-2>=0&&getBit(msk,i)&&getBit(msk,i-1)&&!getBit(msk,i-2))
        {
            int tmsk=setBit0(msk,i);
            tmsk=setBit0(tmsk,i-1);
            tmsk=setBit1(tmsk,i-2);
            ans=max(ans, 1 + fun(tmsk));
        }
    }
    mem[msk]=ans;
    return ans;
}
int main()
{
    int t;
    cin>>t;
    string st;
    while(t--)
   {

       cin>>st;
       int msk=0;
       int cnt=0;
       for(int i=0;i<12;i++)
       {
           if(st[i]=='o')
            msk=setBit1(msk,i),cnt++;
       }
     clr(mem,-1);
      cout<< cnt-fun(msk) <<endl;;

   }
}

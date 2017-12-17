/*
explanation : here the problem is simple dp the state will be f( rounds,sum,nxtbet )
but this state cant fit in memory so ask your self why i need nxtbet to use it in calculations
true every round if i lose i multiply it by 2 so it will be power of 2 so you can only deal with
the power and calculate it yourself it is up to 50 so it is okay .

that is it :)

complexity : O( R*Sum*50 )
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
int R,want;
double p,mem[51][1001][51];
double fun(int r,int cost,int nxt)
{
    if(r==R)
    {
        if(cost==want)
        {
            return 1;
        }
        return 0;
    }

    if(cost==want)
        return 1;
    if(cost>want)
        return 0;

    if(cost<(1<<nxt))
     return 0;

     double &res=mem[r][cost][nxt];
     if(res!=-1)
        return res;

    res=0.0;

    res+= p*fun(r+1,cost+(1<<nxt),0);
    res+= (1-p)*fun(r+1,cost-(1<<nxt),nxt+1);
    return res;
}

 class  TestBettingStrategy
{
     public :
     double winProbability(int initSum, int goalSum, int rounds, int prob)
     {
         int cost;
        cost=initSum;
        want=goalSum;
        R=rounds;
        p=prob; 

        p/=100.0;
        
      for(int i=0;i<=50;i++)
      {
          for(int j=0;j<=1000;j++)
          {
              for(int k=0;k<=50;k++)
                mem[i][j][k]=-1;
          }
      }
      return fun(0,cost,0);   
     } 
};

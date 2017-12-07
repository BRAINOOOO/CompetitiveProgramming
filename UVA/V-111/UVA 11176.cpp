/*
explanation : first of all the expected value is the probability of ocurrance of the event multiplied by it 
the longest streak can be from zero to n so i want the probability of each length of streak multipied by 
its length the question now is how i could get the probability of ocurrance of a certain length of a streak 
if i get the probability of occurance of len from zero to K and from zero to k+1 in the same length so i can
get the probability of occurance of len K in a certain length of games, i will use 2 pointers the first let it be 
i for the number of games and the second let it be j for the length of the streak if j is greater than or equal
i so the probability is 1 bec there is no chance to complement the result ( occurance of streak with j+1 ) if it is smaller 
than by 1 the only state that will complement the result is when j+1 happened and it happens when the total length
of i is winning if the difference more so the chance for making j+1 streak by adding one game is that there is k before
the additional game, at the end just iterate on all lengths of possible streaks and multiply by its problability.

complexity : O( n^2 )
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
double W[500+9],dp[500+9][500+9];
int main()
{
    int n;
    double p;
   while( cin>>n>>p)
   {
       if(n==0)
        break;
       clr(dp,0);
       clr(W,0);
    W[0]=1;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        W[i]=W[i-1]*p;
        dp[0][i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j<i-1)
            dp[i][j]-= dp[i-j-2][j]*(1-p)*W[j+1];
            else if(j+1==i)
            {
                dp[i][j]-=W[i];
            }
        }
    }
double ans=0;
 for(int i=1;i<=n;i++)
 {
     ans+= i* (dp[n][i]-dp[n][i-1]);
 }
  printf("%.5f\n",ans);
}
}

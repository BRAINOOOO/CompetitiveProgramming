/*
explanation : the recurance is i for index j for remaining ones so far k for the flag
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
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1ll;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
string n;
int k,N;
ll dp[1000+9][1000+9][2];
const ll M=1000000007;
int cnt[1000+9];


int main()
{


       cin>>n>>k;
       N=sz(n);
       int c=0;
       for(int i=0;i<N;i++)
       {
           if(n[i]=='1')
            c++;
       }
    cnt[1]=1;

    for(int i=2;i<=1000;i++)
        cnt[i]= cnt[__builtin_popcount(i)]+1;
  ll ans=0;


    for(int f=0;f<2;f++)
      dp[N][0][f]=1;

    for(int i=N - 1;i>=0;i--)
   {

       for(int j=0;j<=N;j++)
       {

           for(int k=0;k<2;k++)
           {


               if(n[i]=='0')
               {

                   dp[i][j][k]= (dp[i][j][k] + dp[i+1][j][k])%M;
                   if(j&&k)
                   dp[i][j][k]= (dp[i][j][k]+ dp[i+1][j-1][k])%M;
               }
               else
               {      if(j)
                   dp[i][j][k]=(dp[i][j][k]+dp[i+1][j-1][k])%M;

                   dp[i][j][k]= (dp[i][j][k]+dp[i+1][j][1])%M;
               }
           }
       }
   }
   for(int i=1;i<=N;i++)
   {
       if(cnt[i]==k)
        ans=(ans+dp[0][i][0])%M;

   }
   if(k==0)
    ans=1;
    else if(k==1)
        ans-=1;
   cout<<ans<<endl;
}

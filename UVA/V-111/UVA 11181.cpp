/*
explanation : here we have conditional probability the whole domain is not the domain i want
to we have a customized domain which is there is exactly r people buy something and my probability
of buying some thing must be within the domain which indicates that there must be r people buying
some thing including me so we just brudeforce.

complexity : O( 2^n * n )
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define    vi       vector<int>
#define    vd       vector<double>
#define    vvi      vector< vector<int> >
#define    vvll      vector< vector<long long> >
#define    vvpi     vector< vector< pair<int,int> > >
#define    vvpll     vector< vector< pair<long long,long long> > >
#define    vvd      vector< vector<double> >
#define    vs       vector<string>
#define    vvs      vector< vector<string> >
#define     vpi        vector< pair<int ,int> >
#define      pi        pair<int ,int>
#define      pll       pair<long long ,long long>
#define     vpd        vector< pair<double ,double> >
#define     vpll        vector< pair<long long ,long long> >
#define    vll       vector<long long>
#define    dqi        deque< int >
#define     si         set<int>
#define     spi        set< pair<int ,int > >
#define     row          vector< ll >
#define     matrix            vector< row >
#define     si         set<int>
#define    oo         900000000000000000
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
int main()
{
   int n,r,cs=1;
   while( cin>>n>>r)
   {
       if(n==0&&r==0)
        break;
      double p[20+9];
    for(int i=0;i<n;i++)
        cin>>p[i];
    double sum[20+9];
    for(int i=0;i<=20;i++)
        sum[i]=0;
   double tot=0;
    for(int i=0;i<=(1<<n)-1;i++)
    {
       double prob=1;
       int cnt=0;
        for(int j=0;j<n;j++)
        {
           if( getBit(i,j) ==1)
           {
               prob*= p[j];
               cnt++;
           }
           else
           {
               prob*=(1-p[j]);
           }
        }
        for(int k=0;k<n;k++)
        {if(cnt==r&&getBit(i,k)==1)
            sum[k]+=prob;
        }
        if(cnt==r)
            tot+=prob;
    }
   printf("Case %d:\n",cs++);
    for(int i=0;i<n;i++)
    {
        printf("%.6f\n",sum[i]/tot);
    }
   }
}

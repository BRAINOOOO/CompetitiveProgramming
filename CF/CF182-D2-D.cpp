/*
explanation : here the first thing you must know is the if the cycle of length C and the 
string length is n so n must be divisable of C and also the length of the other string M
so i will get all the divisors of the small string and get the common with the other string 
and say let the cycle be this len and check for a string if it can be if it can so i will check
the other one if can be or not, actually it is a stright forward idea i try to do other complicated
ideas but i fail and i start thing brude force.

complexity : O( n*squrt(n) )
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define   inf        0x7fffffff
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
#define     vc        vector<char>
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
#define    lp(i,n)    for(i=0;i<n;i++)
#define     si         set<int>
#define    oo         900000000000000000
#define   MOD         1000000007
#define    X            real
#define    Y            imag
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
#define    scani(n)                  scanf("%d",&n)
#define    scanll(n)                  scanf("%I64d",&n)
#define    printi(n)                 printf("%d",n)
#define    printll(n)                 printf("%I64d",n)
#define    scand(n)                  scanf("%lf",&n)
#define    printd(n)                 printf("%lf",n)
#define    scans(n)                  scanf("%s",&n)
#define    prints(n)                 printf("%s",n)
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
const double  PI= acos(-1.0);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int main()
{
   string s1,s2;
    cin>>s1>>s2;
  int n=sz(s1);
  int m=sz(s2);
  int num=min(n,m);
   int i;
   vi v;
   for(i=1;i*i<num;i++)
   {
       if(num%i==0)
       {
           v.pb(i);
           v.pb(num/i);
       }
   }
   if(i*i==num)
    v.pb(i);

   int res=0;
   for(int i=0;i<sz(v);i++)
   {
       if(n%v[i]==0&&m%v[i]==0)
       {
           int flag=1;

           for(int j=0,l=0;j<n;j++,l++)
           {
               if(l==v[i])
                l=0;

               if(s1[j]!=s1[l])
               {
                   flag=0;
                   break;
               }

           }

           if(!flag)
            continue;

           for(int j=0,l=0;j<m;j++,l++)
           {
               if(l==v[i])
                l=0;

               if(s2[j]!=s1[l])
               {
                   flag=0;
                   break;
               }
           }

           if(flag)
            res++;

       }
   }
   cout<<res<<endl;
}

/*
cases

abcabcabe
abcabcabeabcabcabe
1

ababbaababba
ababba
1
*/

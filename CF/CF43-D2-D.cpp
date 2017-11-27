/*
explaination : here will observe that it the max answer wont be greater than 1 by traversing it 
but it may be zero so the point is to discover when it is equal to zero first if  n or m is even 
if the both are odd so it cant be equal to zero but there are some corner cases you should takecare
of which are when the m equal to 1 or n equal to 1 but takecare if n==1 the m must be greater than 2
bec if it is 2 so yu can say ans=0 and the same for if m==1.

complexity : O(nxm)
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
    int n,m;
    cin>>n>>m;
          if((n%2!=0&&m%2!=0)||((m==1&&n>2) || (n==1&&m>2)) )
          {
            if(n>1)
            cout<<"1\n"<<n<<" 1 1 1\n";
            else
            cout<<"1\n"<<"1 "<<m<<" 1 1\n";
          }
          else
            cout<<"0\n";
      if((!(n%2==0&&m%2!=0))||(m==1))
  {
    for(int i=1;i<=m;i++)
    {
        cout<<"1"<<" "<<i<<endl;
    }
    int f=1;
    for(int i=m;i>=1;i--)
    {
        for(int j=2;j<=n&&f;j++)
            cout<<j<<" "<<i<<endl;
        for(int j=n;j>=2&&!f;j--)
            cout<<j<<" "<<i<<endl;
        f=(f+1)%2;
    }
      cout<<"1 1\n";
   }
   else
   {
        for(int i=1;i<=m;i++)
    {
        cout<<"1"<<" "<<i<<endl;
    }
       int f=1;
       for(int i=2;i<=n;i++)
       {
           for(int l=m;l>=2&&f;l--)
            cout<< i<<" "<<l<<endl;
           for(int l=2;l<=m&&!f;l++)
            cout<<i<<" "<<l<<endl;
            f=(f+1)%2;
       }
       for(int i=n;i>=1;i--)
        cout<<i<<" "<<"1\n";
   }
}

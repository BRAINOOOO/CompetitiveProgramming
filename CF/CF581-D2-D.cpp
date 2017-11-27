/*
explanation : here the problem is constructive algorithsm first you need to observe that it is only 3
logos so one will always have the same width of all the square and the 2 others either have the same width
too or not but for sure must have the same length and i wont check whether if their sum of widths equal to
length of square bec it is surely equal to it bec of the check we do it first.

complexity : O(n^3)
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
char c[]={'A','B','C'};
int x[4],y[4];
int main()
{
    int s=0;
    for(int i=0;i<3;i++)
    {
        cin>>x[i]>>y[i];
        s+=(x[i]*y[i]);
    }
   int sq= sqrt(s);
   if(sq*sq!=s)
   {
       cout<<"-1\n";
       return 0;
   }
  int l=sq;
   for(int i=0;i<3;i++)
   {
       if(x[i]>l||y[i]>l)
       {
           cout<<"-1\n";
           return 0;
       }
   }
   vi v;
   for(int i=0;i<3;i++)
   {
       if(y[i]==l)
        swap(x[i],y[i]);
       if(x[i]==l)
        v.pb(i);
   }
   if(sz(v)==3)
   {
      cout<<l<<endl;
       for(int i=0;i<3;i++)
       {
           for(int j=0;j<y[i];j++)
           {
               for(int k=0;k<l;k++)
               {
                   cout<<c[i];
               }
               cout<<endl;
           }
       }
       return 0;
   }
   if(sz(v)==1)
   {
      int cur =  y[v[0]] ;
      int r= l-cur;
      int cnt=0;
       for(int i=0;i<3;i++)
       {
           if(i==v[0])
            continue;
           if(x[i]==r)
            swap(x[i],y[i]);
           if(y[i]==r)
            cnt++;
       }
     if(cnt==2)
     {
         cout<<l<<endl;
         for(int i=0;i<cur;i++)
         {
              for(int j=0;j<l;j++)
              cout<<c[v[0]];
              cout<<endl;
         }
        int f= (v[0]+1)%3;
        int s= (f+1)%3;
             for(int j=0;j<r;j++)
             {

                 for(int k=0;k<x[f];k++)
                 {
                     cout<<c[f];
                 }

                 for(int k=0;k<x[s];k++)
                    cout<<c[s];

                 cout<<endl;
             }
             return 0;
     }
   }

     cout<<"-1\n";
     return 0;
}

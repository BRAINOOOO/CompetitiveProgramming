/*
explanation : here first you have to notice that the answer will never be greater than 
3 so i will handel the case res=1 which is if the points are vertical or horizontal only
case of 2 if 2 points are vertical and the third point's y is not between range of the 2 
points' ys and the same but when the 2 points are horizontal else the ans will be 3.

complexity : O(1)
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
    int x1,x2,x3,y1,y2,y3;
    set<int> s1,s2;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    s1.insert(x1),s1.insert(x2),s1.insert(x3);
    s2.insert(y1),s2.insert(y2),s2.insert(y3);
    int mi,mx;
    if((sz(s1)==1&&sz(s2)==3)||(sz(s1)==3&&sz(s2)==1))
     {
        cout<<"1\n";
        return 0;
     }
     if(y1==y2)
    {
        mi=min(x1,x2);
        mx=max(x1,x2);
        if(!(x3>mi&&x3<mx))
         {
             cout<<"2\n";
             return 0;
         }
    }
    if(y1==y3)
    {
        mi=min(x1,x3);
        mx=max(x1,x3);
        if(!(x2>mi&&x2<mx))
        {
             cout<<"2\n";
             return 0;
        }
    }
     if(y2==y3)
    {
        mi=min(x3,x2);
        mx=max(x3,x2);
        if(!(x1>mi&&x1<mx))
         {
              cout<<"2\n";
              return 0;
         }
    }
      if(x1==x2)
    {
        mi=min(y1,y2);
        mx=max(y1,y2);
        if(!(y3>mi&&y3<mx))
        {
          cout<<"2\n";
          return 0;
        }
    }
     if(x1==x3)
    {
        mi=min(y1,y3);
        mx=max(y1,y3);
        if(!(y2>mi&&y2<mx))
         {
              cout<<"2\n";
              return 0;
         }
    }
    if(x2==x3)
    {
        mi=min(y3,y2);
        mx=max(y3,y2);
        if(!(y1>mi&&y1<mx))
         {
             cout<<"2\n";
             return 0;
         }
    }
        cout<<"3\n";
}

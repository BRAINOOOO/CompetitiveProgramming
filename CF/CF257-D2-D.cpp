/*
explanation : here the sum at the end must be <=a[1] and >=0 so we are searching for the least non negative sum
so as the array is sorted increasingly so we reverse it and subtract second from first as long as the second is 
smaller than the sum so far else we will subtract sum from second, but by subtracting second from sum  we will
need to reverse all pervious signs here you may think that it is TLE but actually it doesnt bec we dont work on
that array we actually work on its reverse so instead of updating all before we will update all next which could 
be done it time.

complexity : O(n)
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
int c[100000+9],b[100000+9];
vi v;
int main()
{
    int n;
    cin>>n;
    int no;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        v.pb(no);
    }
    reverse(all(v));
    int s=v[0];
    c[0]=1;
    for(int i=1;i<n;i++)
    {
        if(s>=v[i])
        {
            s-=v[i];
            c[i]=-1;
        }
        else
        {
            s=v[i]-s;
            c[i]=1;
            b[i]=1;
        }
    }
    reverse(c,c+n);
    reverse(b,b+n);
   int l=1;
    for(int i=0;i<n;i++)
    {
        c[i]=l*c[i];
        if(b[i]==1)
            l*=-1;
    }
    for(int i=0;i<n;i++)
    {
        if(c[i]==1)
            cout<<"+";
        else
            cout<<"-";
    }
}

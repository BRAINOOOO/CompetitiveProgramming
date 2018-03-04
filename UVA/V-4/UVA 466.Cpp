/*
strightforward problem but it requires a smart implementation 
but this doesnt affect get it AC, here first we will check if it is prserved then 
we will check for rotation next for combination its a function deal with rotation 
nxt it is off course improper, to deal with functions something good as the transformations
related.
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
vs v,v1,temp,t2;
int n;
bool isp(vs v=v)
{
    for(int i=0;i<n;i++)
    {
        if(v[i]!=v1[i])
            return 0;
    }
    return 1;
}
bool isv()
{
    for(int i=n-1;i>=0;i--)
    {
        if(v[i]!=v1[n-1-i])
            return 0;
    }
    return 1;
}
int isrot()
{
    string ts="";

    temp.clear();
    for(int i=0;i<n;i++)
    {
        ts="";
        for(int j=n-1;j>=0;j--)
        {
            ts+=t2[j][i];
        }
        temp.pb(ts);
    }
    if(isp(temp))
    {
        return 1;
    }
    return 0;
}
int isrott(vs v)
{
     t2=v;
    int r=0;
     for(int i=90;i<=270;i+=90)
     {
        if(isrot())
       {
         r=i;
         break;
       }
       t2=temp;
     }
     return r;

}
int iscomb()
{
    vs t;
     for(int i=n-1;i>=0;i--)
    {
       t.pb(v[i]);
    }

    return isrott(t);

}
int main()
{
    int bt=1;
    while(cin>>n)
    {
        string st1,st2;
        v.clear();
        v1.clear();
        t2.clear();
        temp.clear();
        for(int i=0;i<n;i++)
        {
            cin>>st1>>st2;
            v.pb(st1);
            v1.pb(st2);
        }

     bool  p=isp();
     bool  i=isv();
     int  c=iscomb();

      t2.clear();
      temp.clear();

     int   r=isrott(v);

       cout<<"Pattern "<<bt++<<" was ";
       if(p)
        cout<<"preserved.\n";
         else if(r!=0)
        cout<<"rotated "<<r<<" degrees.\n";
        else if(i)
        cout<<"reflected vertically.\n";
        else if(c)
            cout<<"reflected vertically and rotated "<<c<<" degrees.\n";
        else
         cout<<"improperly transformed.\n";
    }
}


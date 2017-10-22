
/* 
here is the problem is easy if you know lazy propagation trick, here you have an interval update which cost nlog(n) if you just do it
in the normal way which is TLE so i use lazy propagation to update range in an optimal way
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
int N=100000;
#define ismixed  first
#define  ans     second
 
ll  tree[262143+9];
ll  lazy[262143+9];
 
ll query(int a,int b,int s=1,int e=N,int p=1)
{
    if(a>e||b<s||s>e)
        return 0;
 
     if(lazy[p]!=0)
    {
        tree[p]+=(e-s+1)*lazy[p];
        if(s!=e)
        {
            lazy[2*p]+=lazy[p];
            lazy[2*p+1]+=lazy[p];
        }
        lazy[p]=0;
    }
 
    if(a<=s&&b>=e)
        return tree[p];
 
    int q1 = query(a,b,s,(s+e)/2,p*2);
    int q2 = query(a,b,(s+e)/2+1,e,p*2+1);
 
    return q1+q2;
 
}
 
void lazyupdate(int a,int b,int s=1,int e=N,int p=1)
{
    if(lazy[p]!=0)
    {
        tree[p]+=(e-s+1)*lazy[p];
        if(s!=e)
        {
            lazy[2*p]+=lazy[p];
            lazy[2*p+1]+=lazy[p];
        }
        lazy[p]=0;
    }
 
    if(a>e||b<s||s>e)
        return ;
 
 
    if(a<=s&&b>=e)
    {
        tree[p]+=(e-s+1);
         if(s!=e)
        {
            lazy[2*p]++;
            lazy[2*p+1]++;
        }
 
        return ;
    }
 
    lazyupdate(a,b,s,(s+e)/2,p*2);
    lazyupdate(a,b,(s+e)/2+1,e,2*p+1);
 
    tree[p]=tree[2*p]+tree[2*p+1];
 
 
}
 
 
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
     int n,k;
     scanf("%d %d",&n,&k);
     clr(tree,0);
 
     for(int i=0;i<262143+9;i++)
        lazy[i]=0;
 
     printf("Scenario #");
     printf("%d",cs++);
     printf(":\n");
      while(k--)
      {
        char st[30+9];
        int a,b;
        scanf("%s %d %d",st,&a,&b);
        if(st[0]=='a')
        {
 
 
         printf("%lld\n",query(a,b));
        }
        else
        {
         printf("OK\n");
         lazyupdate(a,b);
 
        }
 
      }
    }
}
 
 

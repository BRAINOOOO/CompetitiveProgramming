/*
here the relation between the lazy and the answer is the lazy will store the whether there is operation on range or not by xoring with one 
if there is relation then reverse if not dont enter 
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
int N=100000,lazy[262143+9],tree[262143+9];
void lazyupdate(int a,int b,int s=1,int e=N,int p=1)
{
    if(lazy[p]!=0)
    {
        tree[p]= (e-s+1)-tree[p];
        if(s!=e)
        {
            lazy[p*2]^=1;
            lazy[2*p+1]^=1;
        }
        lazy[p]=0;
    }
    if(a>e||b<s||s>e)
        return ;

    if(a<=s&&b>=e)
    {
        tree[p]=(e-s+1)-tree[p] ;
        if(s!=e)
        {
            lazy[2*p]^=1;

            lazy[2*p+1]^=1;

        }
        lazy[p]=0;
        return;
    }

    int mid=(s+e)/2;
    lazyupdate(a,b,s,mid,2*p);
    lazyupdate(a,b,mid+1,e,2*p+1);

    tree[p]=tree[2*p]+tree[2*p+1];
}

int query(int a,int b,int s=1,int e=N,int p=1)
{


        if(lazy[p]!=0)
    {
        tree[p]= (e-s+1)-tree[p];
        if(s!=e)
        {
            lazy[p*2]^=1;
            lazy[2*p+1]^=1;
        }
        lazy[p]=0;
    }
    if(a>e||b<s||s>e)
        return 0;

    if(a<=s&&b>=e)
        return tree[p];
    int q1=query(a,b,s,(s+e)/2,2*p);
    int q2=query(a,b,(s+e)/2+1,e,2*p+1);

    return q1+q2;
 }

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int state,a,b;
    for(int i=0;i<m;i++)
    {

        scanf("%d %d %d",&state,&a,&b);
        if(state==0)
            lazyupdate(a,b);
        else
           printf("%d\n", query(a,b)) ;
    }
}

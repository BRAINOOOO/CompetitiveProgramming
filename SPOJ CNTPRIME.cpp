/*
this problem really tests one understanding of the lazy probagation at first you will code and never think that every node at lazy tree 
must express all its children so all the children must be constant in order to expressing them but the ans we will store in each node will
be the sum of the primes in this range and off couse it is not constant and cant do this with lazy so i think that i will divide my job 
in to 2 partions first lazy express the value of the range and when i probagate to tree array i will cnt the sum it is easy but requires 
only to think for 15 mins before coding 
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

int isprime[1000000+9],lazy[327670+9],tree[327670+9],N=10000,er;

void tst()
{
    int n=1000000;
    for(int i=2;i*i<=n;i++)
    {
        if(!isprime[i])
        {
            for(int j=i*2;j<=n;j+=i)
            {

                    isprime[j]=1;
            }
        }
    }
}
ll query(int a,int b,int s=1,int e=N,int p=1)
{


     if(lazy[p]!=0)
    {

        if(isprime[lazy[p]]==0)
         tree[p]=(e-s+1);
         else
            tree[p]=0;
        if(s!=e)
        {
            lazy[2*p]=lazy[p];
            lazy[2*p+1]=lazy[p];
        }
        lazy[p]=0;
    }

    if(a>e||b<s||s>e)
        return 0;
    if(a<=s&&b>=e)
        return tree[p];

    int q1 = query(a,b,s,(s+e)/2,p*2);
    int q2 = query(a,b,(s+e)/2+1,e,p*2+1);

    return q1+q2;

}

void lazyupdate(int a,int b,int val,int s=1,int e=N,int p=1)
{
    if(lazy[p]!=0)
    {

        if(isprime[lazy[p]]==0)
         tree[p]=(e-s+1);
         else
            tree[p]=0;
        if(s!=e)
        {
            lazy[2*p]=lazy[p];
            lazy[2*p+1]=lazy[p];
        }
        lazy[p]=0;
    }

    if(a>e||b<s||s>e)
        return ;


    if(a<=s&&b>=e)
    {
        if(isprime[val]==0)
        tree[p]=(e-s+1);
        else
         tree[p]=0;
         if(s!=e)
        {

            lazy[2*p]=val;
            lazy[2*p+1]=val;
        }
      lazy[p]=0;
        return ;
    }

    lazyupdate(a,b,val,s,(s+e)/2,p*2);
    lazyupdate(a,b,val,(s+e)/2+1,e,2*p+1);

    tree[p]=tree[2*p]+tree[2*p+1];


}

int main()
{
    int t;
    scanf("%d",&t);
    isprime[0]=isprime[1]=1;
   tst();
    for(int cs=1;cs<=t;cs++)
    {
        clr(tree,0);
        clr(lazy,0);

        int n,q;
        scanf("%d %d",&n,&q);
        int no;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&no);

            lazyupdate(i,i,no);
        }
        int state,a,b,v;
        printf("Case %d:\n",cs);
        for(int i=0;i<q;i++)
        {
            scanf("%d",&state);

            if(state==0)
           {
              scanf("%d %d %d",&a,&b,&v);


                  lazyupdate(a,b,v);


           }
           else
           {
               scanf("%d %d",&a,&b);

               printf("%lld\n",query(a,b));

           }

       }
}
}















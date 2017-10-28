/*
here the is to focus on what the query what not the general problem to you will find 3 kinds
of update 1- add range by 1 
          2-remove one from range
          3-reversing 
we need to update on a range so we will use lazy propagation and its state will be 1 or 0 or flipping
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
#define    oo         100000000000000000
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
int tree[2097151+9],lazy[2097151+9],N=1024000;
enum{ CLR=0,ZERO,ONE,FLIP};
string tot;
int doFlip(int x) {
    if( x == ONE ) return ZERO ;
    if( x == ZERO ) return ONE ;
    if( x == FLIP ) return CLR ;
    return FLIP ;
}
void propagate(int p,int s,int e)
{
    if(lazy[p]==CLR)
        return ;
    else if(lazy[p]== ZERO)
    {
         tree[p]=0;

        if(s!=e)
        {
            lazy[2*p]=ZERO;
            lazy[2*p+1]=ZERO;
        }
        lazy[p]=CLR;
    }
    else if(lazy[p]==ONE)
    {
         tree[p]=(e-s+1);

        if(s!=e)
        {
            lazy[2*p]=ONE;
            lazy[2*p+1]=ONE;
        }
        lazy[p]=CLR;
    }
    else
    {
        tree[p]=(e-s+1)-tree[p];

        lazy[2*p]=doFlip(lazy[p]);
        lazy[2*p+1]=doFlip(lazy[p]);

        lazy[p]=CLR;
    }
}









void update1(int a,int b,int s,int e,int p)
{

    propagate(p,s,e);

    if(a>e||b<s||s>e)
        return;


    if(a<=s&&b>=e)
    {
        tree[p]=(e-s+1);
        if(s!=e)
        {
            lazy[p*2]=ONE;
            lazy[2*p+1]=ONE;
        }
        return ;

    }

    update1(a,b,s,(s+e)/2,2*p);
    update1(a,b,(s+e)/2+1,e,2*p+1);

    tree[p]=tree[2*p]+tree[2*p+1];
}
void update0(int a,int b,int s,int e,int p)
{
    propagate(p,s,e);

    if(a>e||b<s||s>e)
        return;



    if(a<=s&&b>=e)
    {
        tree[p]=0;
        if(s!=e)
        {
            lazy[p*2]=ZERO;
            lazy[2*p+1]=ZERO;
        }
        return ;

    }
    update0(a,b,s,(s+e)/2,2*p);
    update0(a,b,(s+e)/2+1,e,2*p+1);

    tree[p]=tree[2*p]+tree[2*p+1];
}
void updatei(int a,int b,int s,int e,int p)
{
    propagate(p,s,e);

    if(a>e||b<s||s>e)
        return;


    if(a<=s&&b>=e)
    {
        tree[p]=(e-s+1)-tree[p];
        if(s!=e)
        {
            lazy[p*2]=doFlip(lazy[2*p]);
            lazy[2*p+1]=doFlip(lazy[2*p+1]);
        }
        return ;

    }
    updatei(a,b,s,(s+e)/2,2*p);
    updatei(a,b,(s+e)/2+1,e,2*p+1);

    tree[p]=tree[2*p]+tree[2*p+1];
}
int query(int a,int b,int s,int e,int p)
{
     propagate(p,s,e);
    if(a>e||b<s||s>e)
        return 0;


    if(a<=s&&b>=e)
        return tree[p];
    int q1=query(a,b,s,(s+e)/2,p*2);
    int q2=query(a,b,(s+e)/2+1,e,p*2+1);
    return q1+q2;
}

int main()
{
    
    int t;
    cin>>t;
    int cs=1;
    while(t--)
    {
        for(int i=0;i<2097151+9;i++)
            lazy[i]=CLR;
        clr(tree,0);
        int m,no;
        cin>>m;
        string st;
        tot="";
        for(int i=0;i<m;i++)
        {
            cin>>no>>st;
         for(int j=0;j<no;j++)
            tot+=st;
        }


        for(int i=0;i<sz(tot);i++)
        {
            if(tot[i]=='1')
                update1(i,i,0,sz(tot)-1,1);

        }

        int q;
        cin>>q;
       int w=1;
        cout<<"Case "<<cs++<<":\n";
        while(q--)
        {
            string ch;
            int a,b;
            cin>>ch>>a>>b;

            if(ch[0]=='F')
                update1(a,b,0,sz(tot)-1,1);
            else if(ch[0]=='E')
                update0(a,b,0,sz(tot)-1,1);
            else if(ch[0]=='I')
                updatei(a,b,0,sz(tot)-1,1);
            else
            {
               cout<<"Q"<<w++<<": "<< query(a,b,0,sz(tot)-1,1) <<endl;

            }
        }

    }
}








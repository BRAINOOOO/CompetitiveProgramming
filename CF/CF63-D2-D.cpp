/*
here by simulation i noticed two methods to prove that at all times it can be done 
since this condition sum of all xi == bxa + cxd butthe idea is to make them connected
so first method is:
if no of columns is even 
take them starting from the second part or the first part traverse row by row from down to up starting 
from zero and then flip till yu reach the the second part.
if odd 
dont start from zero start from the other direction.
the second method is:
doing the same but traverse column by column.
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
char arr[50+9][100+9];
vi v;
int main()
{
    int a1,b1,c1,d1,a,b,c,d,n;
    cin>>a1>>b1>>c1>>d1>>n;
    bool ok=1;
    a=a1;
    b=b1;
    c=c1;
    d=d1;
    int r,cl;
    r=max(b,d);
    cl=a+c;
    int no;
    for(int i=0;i<n;i++)
        cin>>no,v.pb(no);

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<cl;j++)
            arr[i][j]='.';
    }
    char f='a';
    int id=0;
    int flip;
    if(d%2==0)
        flip=0;
    else
        flip=1;
    for(int i=d-1;i>=0&&ok;i--)
    {
        if(flip)
        {
        for(int j=c+a-1;j>=a;j--)
        {
            if(v[id]==0)
            {
                if(id+1<n)
                {
                    id++;
                    f++;
                }
                else
                {
                    ok=0;
                    break;
                }
            }
            arr[i][j]=f;
            v[id]--;
        }
        flip=0;
        }
        else
        {
        for(int j=a;j<a+c;j++)
        {
            if(v[id]==0)
            {
                if(id+1<n)
                {
                    id++;
                    f++;
                }
                else
                {
                    ok=0;
                    break;
                }
            }
            arr[i][j]=f;
            v[id]--;
        }
         flip=1;
        }
    }
         flip=1;
      for(int i=0;i<b&&ok;i++)
    {
        if(flip)
        {
        for(int j=a-1;j>=0;j--)
        {
            if(v[id]==0)
            {
                if(id+1<n)
                {
                    id++;
                    f++;
                }
                else
                {
                    ok=0;
                    break;
                }
            }
            arr[i][j]=f;
            v[id]--;
        }
        flip=0;
        }
        else
        {
        for(int j=0;j<a;j++)
        {
            if(v[id]==0)
            {
                if(id+1<n)
                {
                    id++;
                    f++;
                } else
                {
                    ok=0;
                    break;
                }
            }
            arr[i][j]=f;
            v[id]--;
       }
         flip=1;
        }
    }
   cout<<"YES\n";

   for(int i=0;i<r;i++)
   {
       for(int j=0;j<cl;j++)
       {
           cout<<arr[i][j];
       }
       cout<<endl;
   }
}

/*
here the must observation is the local signs will be different as he say so only 
deal with 26 chars the subproblem know is how we can respond to each query in o(1)
here we will make a preprocessing 2d array to calculate for each column the number 
of the '#' sea cells per range and the same for each row another 2d array.

complexity : o( q*26 )
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
const int N =1000+9;
char v[N][N];
int cl[N][N],rw[N][N],nu[100000+9];
string s[100000+9];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>v[i][j];
        }
    }
    int q;
    cin>>q;
    vpi v1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[i][j]=='#')
            {
                cl[i][j]=cl[i][j-1]+1;
            }
            else
                cl[i][j]=cl[i][j-1];

            if(v[i][j]>='A'&&v[i][j]<='Z')
                v1.pb(mp(i,j));



        }
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(v[j][i]=='#')
            {
                rw[j][i]=rw[j-1][i]+1;
            }
            else
                rw[j][i]=rw[j-1][i];
        }
    }
    string st;
    int num;
    for(int i=0;i<q;i++)
    {
        cin>>st>>num;

        s[i]=st;
        nu[i]=num;
    }

    string ans="";

    for(int i=0;i<sz(v1);i++)
    {
       int r=v1[i].first;
       int c=v1[i].second;
       char ch=v[r][c];
       bool ok=1;

      for(int j=0;j<q;j++)
      {


         st=s[j];
         num=nu[j];
         int val;
         if(st=="N")
         {
             if(r-num>=1)
           val= rw[r][c]-rw[r-num-1][c];
           else
            val=5;

           if(val!=0)
           {
             ok=0;
             break;
           }
           r=r-num;
         }
         else if(st=="S")
         {
             if(r+num<=n)
           val= rw[r+num][c]-rw[r-1][c];
           else
            val=5;

           if(val!=0)
           {
               ok=0;
               break;
           }

           r=r+num;

         }
         else if(st=="W")
         {
             if(c-num>=1)
             val= cl[r][c]-cl[r][c-num-1];
             else
                val=5;

              if(val!=0)
             {
               ok=0;
               break;
             }
             c=c-num;

         }
         else if(st=="E")
         {
             if(c+num<=m)
             val= cl[r][c+num]-cl[r][c-1];
             else
                val=5;
            if(val!=0)
           {
               ok=0;
               break;
           }
           c=c+num;
         }
      }
      if(ok)
       ans+=ch;
    }

    sort(all(ans));
   if(ans=="")
    cout<<"no solution\n";
    else
    cout<< ans << endl;
}


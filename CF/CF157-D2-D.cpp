/*
explanation : here the request will be considered to be undefined if it can be true and false 
so if we accuse some one so it is true if he can be the only crimeal and false if he cant be the 
crimenal at all undefined if he can be the crimenal but there is other possible criminals too, 
for justifing request true if he cant be the crimnal at all false if he is the only crimnal else
else undefined, so we need to know how can be the criminal we can do so by check if number of lias
fit in condition we can calculate it by counting the number of requests accusing other susbects 
and the number that justifing it.

complexity : O(N)
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
char C[100000+9];
int D[100000+9],a[100000+9],b[100000+9];
int main()
{
    int n,m;
    cin>>n>>m;
    int no;
    char ch;
    int cnts=0;
    int cntss=0;
    for(int i=0;i<n;i++)
    {
        cin>>ch>>no;
        C[i]=ch;
        D[i]=no;
        if(ch=='+')
        {
            a[no]++;
            cnts++;
        }
        else
          cntss++,  b[no]++;
    }
  map<int,int> mb;
    for(int i=1;i<=n;i++)
    {
      int  lie= cnts-a[i]+b[i];
        if(lie==n-m)
        {
            mb[i]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
       int d=D[i];
        if(C[i]=='+')
        {
            if(mb.find(d)!=mb.end()&&sz(mb)==1)
            {
                cout<<"Truth\n";
            }
            else if(mb.find(d)!=mb.end()&&sz(mb)>1)
                cout<<"Not defined\n";
            else if(mb.find(d)==mb.end())
             cout<<"Lie\n";
        }
        else
        {
            if(mb.find(d)!=mb.end()&&sz(mb)==1)
            {
                cout<<"Lie\n";
            }
            else if(mb.find(d)!=mb.end()&&sz(mb)>1)
                cout<<"Not defined\n";
            else if(mb.find(d)==mb.end())
             cout<<"Truth\n";
        }
    }
}

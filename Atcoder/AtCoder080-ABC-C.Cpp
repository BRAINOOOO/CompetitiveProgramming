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
ll mx=-1000000000;
vs v;
ll p[100+9][10+9],n;
bool check2(string s)
{
    for(int i=0;i<10;i++)
    {
        if(s[i]=='1')
            return 1;
    }
    return 0;
}
ll check(string s)
{
    ll res=0;
    for(int i=0;i<n;i++)
    {
        ll cnt=0;
        for(int j=0;j<10;j++)
        {
            char ch= v[i][j];
           if(( ch == s[j]) && (s[j]=='1' ) )
           {
               cnt++;
           }
        }
        res+= p[i][cnt];
    }
    return res;
}
void fun(int id,string s)
{
    if(id==10)
    {
      if(check2(s))
      mx=max(mx,check(s));
     return ;
 
    }
    fun(id+1,s+"0");
    fun(id+1,s+"1");

}
int main()
{
    cin>>n;
    ll no;
    for(int i=1;i<=n;i++)
    {
        string s1="";
        for(int j=1;j<=10;j++)
        {
            cin>>no;
 
            if(no==1)
                s1+="1";
            else
                s1+="0";
        }
        v.pb(s1);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=10;j++)
        {
            cin>>no;
            p[i][j]=no;
        }
    }
    string s="";
    fun(0,s);
    cout<< mx <<endl;
}

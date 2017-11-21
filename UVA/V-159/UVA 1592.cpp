/*
explanation : here the problem idea is direct the point is the direct complexity
is TLE so i will use map to fit in time, i will map each pair of strings i passed
before to its row and every time i will check if i passed this before or not.

complexity : ((m(m-1))/2) * n * log(n) 
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
int main()
{
   int n,m;
  while( cin>>n>>m )
  {
    cin.ignore();
    vector< vector<string> > v(10000+9);
    for(int i=0;i<n;i++)
    {
        string st;
        getline(cin,st);
        st+=',';
        string s="";
        for(int j=0;j<sz(st);j++)
        {
            if(st[j]==',')
            {
                v[i].pb(s);
                s="";
                continue;
            }
            s+=st[j];
        }
    }
    map< pair<string,string>,int> mb;
    bool ok=1;
    int r1,r2,c1,c2;
    for(int i=0;i<m&&ok;i++)
    {
        for(int j=i+1;j<m&&ok;j++)
        {
            mb.clear();
            for(int l=0;l<n;l++)
            {
             string  s1= v[l][i];
             string  s2= v[l][j];
               if(mb.find(mp(s1,s2))!=mb.end())
               {
                   ok=0;
                   c1=i+1;
                   c2=j+1;
                   r2=l+1;
                   r1=mb[mp(s1,s2)]+1;
                   break;
               }
               mb[mp(s1,s2)]=l;
            }
        }
    }
    if(!ok)
    {
        cout<<"NO\n"<<r1<<" "<<r2<<endl<<c1<<" "<<c2<<endl;
    }
    else
        cout<<"YES\n";
  }
}

/*
topic : greedy

explanation : the idea is we want to maxmize the the sum so we want to maxmize the area
so we want to maxmize the radius so i will sort all the radii and pick the first at 1st
set and the second to second then every coming circle i will put it where it will includes
even number of circles if it cant be so it doesnt matter to put it in any set.

complexity : O( n^2 )
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
bool check(ll x1,ll y1,ll r1,ll x2,ll y2,ll r2)
{
   ll a=(x2-x1)*(x2-x1);
   ll b=(y2-y1)*(y2-y1);

    return (a+b)<=r2*r2;
}
int main()
{
    int n;
    cin>>n;
    vector< pair< ll,pll> > v,fst,sec;
    int x,y,r;

    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>r;
        v.pb(mp(r,mp(x,y)));
    }
    sort(allr(v));
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(sz(fst)==0)
        {
            fst.pb(v[i]);
            ans+= v[i].first*v[i].first;
        }
        else if(sz(sec)==0)
        {
            sec.pb(v[i]);
            ans+=v[i].first*v[i].first;
        }
        else
        {
            int f=0,s=0;
            for(int j=0;j<sz(fst);j++)
            {
                if(check(v[i].second.first,v[i].second.second,v[i].first,fst[j].second.first,fst[j].second.second,fst[j].first))
                    f++;
            }
            for(int j=0;j<sz(sec);j++)
            {
               if(check(v[i].second.first,v[i].second.second,v[i].first,sec[j].second.first,sec[j].second.second,sec[j].first))
                    s++;
            }

            if(f%2==0)
            {
                fst.pb(v[i]);
                ans+= v[i].first*v[i].first;
            }
            else if(s%2==0)
            {
                sec.pb(v[i]);
                ans+= v[i].first*v[i].first;
            }
            else
            {
                fst.pb(v[i]);
                ans-= v[i].first*v[i].first;

            }

        }
    }

    cout<<fixed<<setprecision(9)<<ans*acos(-1)<<endl;
}


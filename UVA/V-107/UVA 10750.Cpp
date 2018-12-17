#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define   y            imag()
#define   x            real()
#define    clr(v,d)      memset( v, d ,sizeof(v))
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
#define outfile freopen("out.out", "w", stdout);
#define infile  freopen("in.in", "r", stdin);
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-8);
using namespace std;
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}

struct cmpY
{
    bool operator()(const point &a,const point &b)
    {
        if(dcmp(a.y,b.y)!=0)
            return dcmp(a.y,b.y)<0;
        return dcmp(a.x,b.x)<0;
    }
};

struct cmpX
{
    bool operator()(const point &a,const point &b)
    {
        if(dcmp(a.x,b.x)!=0)
            return dcmp(a.x,b.x)<0;

        return dcmp(a.y,b.y)<0;
    }
};




point ans1,ans2;
const long double inf=1e20;
void closestpair(vector<point> &events)
{

    long double d=inf;
    int left=0;
    sort(all(events),cmpX());
    multiset< point,cmpY> activeset;
    for(int i=0;i<sz(events);i++)
    {

        while(left<i&&events[i].x-events[left].x>d)
            activeset.erase(activeset.find(events[left++]));

        auto strit= activeset.lower_bound(point(-inf,events[i].y-d));
        auto enit=activeset.upper_bound(point(-inf,events[i].y+d));

        for(;strit!=enit;strit++)
        {
            long double dd= length((events[i]-(*strit)));

            if(dcmp(d,dd)>=0)
            {
                d=dd;
                ans1=events[i];
                ans2= (*strit);
            }


        }

        activeset.insert(events[i]);
    }
}













int main()
{
    int T;
    cin>>T;
    int in=0;
    while(T--)
    {
        if(in)
            cout<<endl;
        int n;
        cin>>n;
        vector<point> v;
         double xx,yy;
        in=1;
        for(int i=0;i<n;i++)
        {
            cin>>xx>>yy;
            v.pb(point(xx,yy));

        }

        closestpair(v);
        point mid=(ans1+ans2);
        cout<<fixed<<setprecision(3)<<mid.x/2.0<<" "<<mid.y/2.0<<endl;

    }
}


#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define   Y            imag()
#define   X            real()
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
vector< pair<double,ll> > v;
int main()
{
    freopen("walk.in", "r", stdin);
    int T;
    scanf("%d",&T);

    while(T--)
    {
        v.clear();
        ll n,m;
        scanf("%I64d %I64d",&n,&m);
        ll x,y,r;
        for(int i=0;i<n;i++)
        {
            scanf("%I64d %I64d %I64d",&x,&y,&r);

            if(abs(y)<=m-r)
            {

                double delta= sqrt(((m-r)*(m-r))-(y*y));

                v.pb(mp(x-delta,r));
                v.pb(mp(x+delta+eps,-r));



            }

        }

        sort(all(v));
        ll mx=0,cur=0;
        for(int i=0;i<sz(v);i++)
        {
            cur+= v[i].second;
            mx=max(mx,cur);
        }

        printf("%I64d\n",mx);
    }
}


















































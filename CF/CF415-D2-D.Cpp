/*
explanation : the only thing that may delay you from solve is the order of divisors is sqrt(n) but their number is very small
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
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
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1ll;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
const ll MOD=1000000007;
vector< vector<int> > v(2001);
ll mem[2001][2001],n,k;
void cald(int n)
{
    int sq=ceil(sqrt(n)),i;

    for(i=1;i<sq;i++)
    {
        if(n%i==0)
        {
            v[n].pb(i);
            v[n].pb(n/i);
        }
    }
    if(i*i==n)
        v[n].pb(i);
}
ll solve(int id,int bef)
{
    if(id==-1)
        return 1;

    ll &ret=mem[id][bef];
    if(ret!=-1)
        return ret;
    ll res=0;
    if(bef==0)
    {
        for(int i=1;i<=n;i++)
           res=(res+ solve(id-1,i))%MOD;
    }
    else
    {
        for(int i=0;i<sz(v[bef]);i++)
        {
           res= (res+solve(id-1,v[bef][i]))%MOD;
        }
    }
    ret=res;
    return ret;
}
int main()
{
    M();
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cald(i);
    }
   clr(mem,-1);
   cout<< solve(k-1,0)<<endl;
}

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
int mem[105][10005];
int N,k;
const int inf=100000000;
typedef struct N
{
    int n,l,p;
    N(int n,int l,int p) : n(n),l(l),p(p) {}
}  node ;
vector< vector<node> > v(105);
int solve(int n,int k)
{
    int &ret=mem[n][k];
    if(ret!=-1)
        return ret;

    if(n==N)
     return ret=0;
    int ans=inf;

    for(int i=0;i<sz(v[n]);i++)
    {
        int price= v[n][i].p;
        if(k>=price)
        ans=min(ans, v[n][i].l+ solve(v[n][i].n,k-price));
    }
    return ret=ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
       int r;
        v.clear();
        v.resize(109);

        cin>>k>>N>>r;
        int f,t,l,p;
        for(int i=0;i<r;i++)
        {
            scanf("%d %d %d %d",&f,&t,&l,&p);

            v[f].pb(node(t,l,p));
        }
        clr(mem,-1);
        int res=solve(1,k);

        if(res==inf)
            printf("-1\n");
        else
            printf("%d\n",res);

    }
}

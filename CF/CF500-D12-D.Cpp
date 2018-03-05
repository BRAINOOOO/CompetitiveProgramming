/*
explanation : editorial ----> http://codeforces.com/blog/entry/15488
              helpful comment ----->  http://codeforces.com/blog/entry/15488?#comment-204381
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
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
ll arr[100009],dep[100009],W[100009],N;
vector< vector< pair<int,int> > > v(100009);
void dfs(int id,int p)
{

    arr[id]=1;

    for(int i=0;i<sz(v[id]);i++)
    {
        int no=v[id][i].first;
        int ed=v[id][i].second;
        if(no==p)
            continue;
        dfs(no,id);
        arr[id]+= arr[no];
        dep[ed]= arr[no]*(N-arr[no]);
    }
}
int main()
{
    cin>>N;
    int f,t,w;
    for(int i=1;i<N;i++)
    {
        cin>>f>>t>>w;
        v[f].pb(mp(t,i));
        v[t].pb(mp(f,i));
        W[i]=w;
    }
    dfs(1,-1);
    double ans=0.0;
    for(int i=1;i<N;i++)
        ans+= dep[i]*W[i];
    ans*=2;
    int q;
    cin>>q;
    int e,nw;
    while(q--)
    {
        cin>>e>>nw;
       ll sub= (W[e]-nw)*dep[e]*2;
        ans-=sub;
        W[e]=nw;
        cout<<fixed<<setprecision(9)<< (ans*3.0)/(N*(N-1))<<endl;
    }
}

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
ll dist[105],vis[109];
ll N,k;
const ll inf=10000000000000000;
struct node
{
    ll n,l,p;

    node(ll n,ll l,ll p) : n(n),l(l),p(p) {}
    bool operator < (const node &e) const
    {
        return l>e.l;
    }
};
ll dijk(vector< vector<node> > v)
{
    clr(vis,0);
   for(int i=0;i<109;i++)
    dist[i]=inf;

    dist[1]=0;

    priority_queue< node > pq;

    pq.push(node(1,0,0));

    while(!pq.empty())
    {
       node cur= pq.top();
       int myp=cur.p;
       pq.pop();

       if(cur.n==N)
       {
           return cur.l;
       }

       ll add=cur.l;

       for(int i=0;i<sz(v[cur.n]);i++)
       {

          node nw= v[cur.n][i];

          int cost=nw.l;
          int price=nw.p;

          if(k<price+myp)
             continue;


              pq.push(node(nw.n,add+cost,myp+price));


       }
    }
    return -1;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
       int r;

        cin>>k>>N>>r;
        vector< vector<node> > v(109);
        ll f,t,l,p;
        for(int i=0;i<r;i++)
        {
            cin>>f>>t>>l>>p;

            v[f].pb(node(t,l,p));
        }

       cout<< dijk(v)<<endl;
    }
}



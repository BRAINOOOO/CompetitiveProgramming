/*
explanation : here is the problem is i have a limited distance to travel by each taxi at each node so i will get the min distance from 
each node to all other nodes and see waht it fits with the limited distance of the current node taxi and connects it with taxi cost
then min a mong cost so get to target from source :)
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
const ll inf=1000000000000000;
vector<ll> dist(1000+9);
ll C[1000+9],D[1000+9];
struct node
{
    ll n,w;
    node(ll n,ll w) : n(n),w(w) {}
    bool operator < ( const node &e) const
    {
        return w>e.w;
    }
};
void dijkstra(vector<vector<node>> v,ll s)
{
    fill(all(dist),inf);
    vector<ll> vis(1000+9);
    fill(all(vis),0);
    priority_queue< node > pq;
    pq.push(node(s,0));
    dist[s]=0;
    while(!pq.empty())
    {
       node cur= pq.top();
       pq.pop();
       if(vis[cur.n])
        continue;
       vis[cur.n]=1;
        ll add=dist[cur.n];
        for(int i=0;i<sz(v[cur.n]);i++)
        {
            node nw=v[cur.n][i];
            if(dist[nw.n]>add+nw.w)
            {
                dist[nw.n]= add+nw.w;
                pq.push(node(nw.n,add+nw.w));
            }
        }
    }
}
int main()
{
    ll n,m,cp,en,st;
    scanf("%I64d %I64d %I64d %I64d",&n,&m,&st,&en);
    vector< vector<node> > v(1000+9);
    ll f,t,w;
    for(int i=0;i<m;i++)
    {
        scanf("%I64d %I64d %I64d",&f,&t,&w);
        v[f].pb(node(t,w));
        v[t].pb(node(f,w));
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&D[i],&C[i]);
    }
    vector< vector< node > > v1(1000+9);
    for(int i=1;i<=n;i++)
    {
        ll d=D[i];
        ll c=C[i];
        dijkstra(v,i);
        for(int j=1;j<=n;j++)
        {
              if(j==i)
                continue;
             if(dist[j]<=d)
             {
                 v1[i].pb(node(j,c));        
             }
        }
    }
    dijkstra(v1,st);
    printf("%I64d\n",(dist[en]==inf ? -1: dist[en]));
}

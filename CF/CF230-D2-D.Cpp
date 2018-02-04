/*
explanation : here if the problem without the part of i must wait for a second if there is other passengers arrive on the same time
with me it will be direct shortest path problem dijkstra now for the second part of the problem i will add the cost on each branch from
this node .
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
const ll inf=100000000000000000;
ll dist[100000+9];
vector<ll> arr[100000+9];
struct node
{
    ll no,w;
    node(ll no,ll w) : no(no),w(w) {}
    bool operator < ( const node &e) const
    {
        return w> e.w;
    }
};
void dijkstra(vector<vector<node> > v,ll s,ll tar)
{
    clr(dist,-1);
    priority_queue< node > pq;
    pq.push(node(s,0));
    while(!pq.empty())
    {
       node cur=pq.top();
       pq.pop();
       if(dist[cur.no]!=-1)
        continue;
       dist[cur.no]=cur.w;
       if(cur.no==tar)
        return ;
      auto it= lower_bound(all(arr[cur.no]),dist[cur.no]);
      ll add=dist[cur.no];
      while(it!=arr[cur.no].end()&&(*it)==add)
      {
          add++;
          it++;
      }
      for(int i=0;i<sz(v[cur.no]);i++)
      {
          node nw=v[cur.no][i];
          if(dist[nw.no]==-1)
            pq.push(node(nw.no,add+nw.w));
      }
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector< vector<node> > v(100000+9);
    ll f,t,w;
    for(int i=0;i<m;i++)
    {
         scanf("%I64d%I64d%I64d",&f,&t,&w);
        v[f].pb(node(t,w));
        v[t].pb(node(f,w));
    }
    ll k,ti;
    for(int i=1;i<=n;i++)
    {
         scanf("%I64d",&k);
        for(int j=0;j<k;j++)
        {
             scanf("%I64d",&ti);
            arr[i].pb(ti);
        }
    }
    dijkstra(v,1,n);
   printf("%I64d\n",dist[n] );
}

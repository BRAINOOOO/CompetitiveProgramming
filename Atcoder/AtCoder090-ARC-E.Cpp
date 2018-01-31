/*
explanation : first i will get  the shortest path between the two nodes S and T assuming that they may meet each other and i will do
preprocessing for the number of the shortest paths to reach a node from source S so i can get the number of paths to reach node t from 
source S and the answer will be permutation of number of paths of length two ( noofpaths^2 ) but they may meet first of all they may meet
at a certain node or at a certain edge they meet at a certain node if the dist to this node from S and from T to this node equal and sum
of them equal to shortest path so i will check all the nodes and subtract from answer or they may meet at a certain edge 
say connects node A to B so from to node A in less than  shortest path/2 and same from T to node B so will meet at this edge so i will
check edges and subtract.

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
#define sq(n)    ((n)*(n))
vector<ll> num;
vector<ll> dist;
const ll inf=1000000000000000000,M=1000000007;
struct edge
{
    int f,t;
    ll w;
    edge(int f,int t,ll w) : f(f),t(t),w(w) {}
    bool operator < ( const edge &e) const{
    return w>e.w;
    }
};
void dijkstra(vector< vector<edge> > v,int s)
{
    int n=sz(v);
    num.resize(n);
    dist.resize(n);
    fill(all(num),0);
    fill(all(dist),inf);
    dist[s]=0;
    num[s]=1;
    priority_queue< edge > pq;
    pq.push(edge(-1,s,0));
    while(!pq.empty())
    {
      edge cur =pq.top();
      pq.pop();
      if(cur.w>dist[cur.t])
        continue;
      for(int i=0;i<sz(v[cur.t]);i++)
      {
          edge  nw= v[cur.t][i];
          if(dist[nw.t]> nw.w+dist[nw.f])
          {
             nw.w= dist[nw.t]=nw.w+dist[nw.f];
             num[nw.t]=num[cur.t];
              pq.push(nw);
          }
          else if(dist[nw.t]==nw.w+dist[nw.f])
          {
              num[nw.t]=(num[nw.t]+num[cur.t])%M;
          }
      }
    }
}
int main()
{
      int n,m,s,t;
     cin>>n>>m>>s>>t;
     vector< vector<edge > > v(200000+9);
     vector< pair<pair<int,int>,ll> > e;
     int f,to;
     ll w;
     for(int i=0;i<m;i++)
     {
         cin>>f>>to>>w;
         e.pb(mp(mp(f,to),w));
         v[f].pb(edge(f,to,w));
         v[to].pb(edge(to,f,w));
     }
         dijkstra(v,s);
      vector<ll>   numofpaths1=num;
      vector<ll>  dist1=dist;
         dijkstra(v,t);
      vector<ll>  numofpaths2=num;
      vector<ll>   dist2=dist;
         ll ff=numofpaths1[t];
         ll dd=dist1[t];
       ll  ans= (ff*ff)%M;
         for(int i=1;i<=n;i++)
         {
             if(dist1[i]+dist2[i]==dd&&dist1[i]==dist2[i])
             {
                 ans= (ans- sq(numofpaths1[i]*numofpaths2[i]%M)%M+M)%M;
             }
         }
         for(int i=0;i<sz(e);i++)
         {
            f= e[i].first.first ;
            to= e[i].first.second;
            w= e[i].second;
              if(dist1[f]>dist1[to])
             swap(f,to);
            if(dist2[to]+dist1[f]+w==dd&&dist2[to] < (((double)dd)/2) && dist1[f] < (((double)dd)/2))
                ans= (ans- (sq((numofpaths2[to]*numofpaths1[f])%M)%M)+M)%M;
         }
          cout<<ans<<endl;
}

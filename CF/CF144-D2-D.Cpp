/*
explanation : first of all the direct part is to run dijkstra to get the shortest paths to each node from capital 
and iterate on the nodes and count the number of nodes its shortest path from capital is L then for the second part
if the missels exist on an edge let it be
                                                    A----------------B
                                         
                                        shortest dist to A from capital must be less than L and this dist plus edge must be greater
                                        than L to grante that there is a point on the edge its distance from it to capital equal to L
                                        this point can reach capital whether through node A or node B i will take it L distance from 
                                        capital using A and check if this point can reach capital with shorter distance through B
                                        if yes don't count it else count it and do the same for node B .
                                        
                                        But if B shortest path to capital depends on A or vice versa so i have only one choice to
                                        take the point from the node nearer to capital . :)
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
vector< pair< pair<int,int> ,int> > e;
vector<ll> dist(100000+9);
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
    vector<ll> vis(100000+9);
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
    ll n,m,cp;
    cin>>n>>m>>cp;
    vector< vector<node> > v(100000+9);
    ll f,t,w;
    for(int i=0;i<m;i++)
    {
        cin>>f>>t>>w;
        e.pb(mp(mp(f,t),w));
        v[f].pb(node(t,w));
        v[t].pb(node(f,w));
    }
    ll l;
    cin>>l;
    dijkstra(v,cp);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
       if( dist[i]==l )
        ans++;
    }
    for(int i=0;i<m;i++)
    {
        ll A= e[i].first.first;
        ll B= e[i].first.second;
        ll elen=e[i].second;
        ll p1=-1,p2=-1;
        if((dist[A]+elen==dist[B]&&dist[B]>l&&dist[A]<l)||(dist[B]+elen==dist[A]&&dist[A]>l&&dist[B]<l))
         {
             ans++;
             continue;
         }
         if((dist[A]+elen==dist[B]))
            continue;
         if((dist[B]+elen==dist[A]))
            continue;
         if(dist[A]<l&&dist[A]+elen>l)
         {
             p1=l-dist[A];
            ll dp1=elen-p1+dist[B];
             if(dp1<l)
             p1=-1;
         }
         if(dist[B]<l&&dist[B]+elen>l)
         {
             p2=elen-(l-dist[B]);
            ll dp2=p2+dist[A];
             if(dp2<l)
                p2=-1;
         }
        if(p1==-1&&p2==-1)
            continue;
        if(p1==-1||p2==-1)
            ans++;
        else
        {
            if(p1==p2)
                ans++;
            else
              ans+=2;
        }
    }
    cout<<ans<<endl;
}

/*
topic : graph( dijkstra-floyed-dfs)

explanation : here the idea is all the edges are +ve so we will deal with all
the blocks as blocks not considering the internal sides as it will not affect 
the min distance between the blocks as the edges are +ve so i will increase the
distance can do it by floyed or by dijkstra, here the second part we want to know
whether it is correct or not we can do so that by he say that it is correct if by 
only zero edges i can reach all nodes of each partion so i will remove each non 
zero edge and do dfs from begin of each partion and count only nodes that belong
to my part if it is equal to what it should be right else wrong.

complexity : o( k^2 log(k) ) dijkstra
             o(K^3)          floyed

*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define   inf        0x7fffffff
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define    vi       vector<int>
#define    vd       vector<double>
#define    vvi      vector< vector<int> >
#define    vvll      vector< vector<long long> >
#define    vvpi     vector< vector< pair<int,int> > >
#define    vvpll     vector< vector< pair<long long,long long> > >
#define    vvd      vector< vector<double> >
#define    vs       vector<string>
#define    vvs      vector< vector<string> >
#define     vc        vector<char>
#define     vpi        vector< pair<int ,int> >
#define      pi        pair<int ,int>
#define      pll       pair<long long ,long long>
#define     vpd        vector< pair<double ,double> >
#define     vpll        vector< pair<long long ,long long> >
#define    vll       vector<long long>
#define    dqi        deque< int >
#define     si         set<int>
#define     spi        set< pair<int ,int > >
#define     row          vector< ll >
#define     matrix            vector< row >
#define    lp(i,n)    for(i=0;i<n;i++)
#define     si         set<int>
#define    oo         900000000000000000
#define   MOD         1000000007
#define    X            real
#define    Y            imag
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
#define    scani(n)                  scanf("%d",&n)
#define    scanll(n)                  scanf("%I64d",&n)
#define    printi(n)                 printf("%d",n)
#define    printll(n)                 printf("%I64d",n)
#define    scand(n)                  scanf("%lf",&n)
#define    printd(n)                 printf("%lf",n)
#define    scans(n)                  scanf("%s",&n)
#define    prints(n)                 printf("%s",n)
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
const double  PI= acos(-1.0);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
map< int ,int > mb;
int f[100000+9],t[100000+9],w[100000+9],vis[100000+9];
vvi arr2(100000+9);
int N,cnt;
void dfs(int id,int t)
{
    if(vis[id])
        return;
    vis[id]=1;

    if(mb[id]==t)
    cnt++;

    for(int i=0;i<sz(arr2[id]);i++)
        dfs(arr2[id][i],t);
}
struct edge
{
    int from,to,w;

    edge (int from,int to,int w) : from(from),to(to),w(w) {}

    bool operator < ( const edge &e)
    const {

            return w > e.w;
    }
};
vi dik( vector< vector<edge> > adj ,int s)
{
    int n=sz(adj);
    vi dist(n,1000000010),pre(n,-1);
    dist[s]=0;
    priority_queue<edge> q;
    q.push(edge(-1,s,0));
    while(!q.empty())
    {
        edge e=q.top();
        q.pop();
        if(e.w>dist[e.to])
            continue;
            pre[e.to]=e.from;
            for(int j=0;j<sz(adj[e.to]);j++)
            {
                edge ne=adj[e.to][j];
                if(dist[ne.to]>dist[ne.from]+ne.w)
                {

                    ne.w=dist[ne.to]=dist[ne.from]+ne.w;
                    q.push(ne);
                }
            }
    }
    return dist;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    N=k;
    int K[500+9];
    for(int i=1;i<=k;i++)
    {
       cin>> K[i];

    }
   int l=1;
    for(int id=1;id<=k;id++)
    {
        for(int j=1;j<=K[id];j++)
          mb[l]=id,l++;
    }
    vector< vector< edge > > arr(k+9);
    for(int i=0;i<m;i++)
    {
        int u,v,x;
        cin>>u>>v>>x;
        f[i]=u;
        t[i]=v;
        w[i]=x;
        if(mb[u]==mb[v])
        {
           ;
        }
        else
        {
            arr[mb[u]].pb(edge(mb[u],mb[v],x));
            arr[mb[v]].pb(edge(mb[v],mb[u],x));
        }

    }
   int u,v,x;
      for(int i=0;i<m;i++)
      {
          u=f[i];
          v=t[i];
          x=w[i];

          if(x==0)
          arr2[u].pb(v),arr2[v].pb(u);

      }
     int flag=0;
      l=1;
      for(int i=1;i<=k;i++)
      {

         cnt=0;
         clr(vis,0);
         dfs(l,i);
         if(K[i]!=cnt)
         {
             flag=1;
             break;
         }
         l+=K[i];


      }
      if(flag)
      {
          cout<<"No";
          return 0;
      }
    cout<<"Yes\n";
   int res[500+9][500+9];
    for(int i=1;i<=k;i++)
    {
        vi dist= dik(arr,i);

        for(int j=1;j<=k;j++)
            res[i][j]=(dist[j]==1000000010 ? -1 : dist[j]);
    }

    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
}

/*
direct applying of dijkstra algorithsm
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
typedef struct Node
{
    int no;
    double w;
    Node(int no,double w) : no(no),w(w) {}

    bool operator < (const Node &e) const
    {
        return dcmp(w,e.w)==1;
    }
}N;

vector< vector<N> > v(109);
int X[109],Y[109],S[109];
double distce(int a,int b)
{
    int x1=X[a]; int y1=Y[a];  int x2=X[b]; int y2=Y[b];
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
double dist[109]; int vis[109]; double inf=1e18;
void dijkstra()
{
    for(int i=0;i<109;i++)
        dist[i]=inf;
    clr(vis,0);

    priority_queue< N> pq;
    pq.push(N(1,0));

    dist[1]=0;

    while(!pq.empty())
    {

         N cur=pq.top();
         pq.pop();
         if(vis[cur.no])
            continue;

          vis[cur.no]=1;

         double add= dist[cur.no];
         int cnt=S[cur.no];

         for(int i=0;i<sz(v[cur.no])&&cnt;i++)
         {
             N nw= v[cur.no][i];
              if(!vis[nw.no])
              {
                cnt--;
             if(dist[nw.no]> add+nw.w)
             pq.push(N(nw.no,add+nw.w)),dist[nw.no]=add+nw.w;
              }
         }

    }
}













int main()
{

    int n;
    cin>>n;
    int x,y,s;
    vector< vector<int> > v1(109);
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>s;

        X[i]=x;  Y[i]=y; S[i]=s;
        int no;
        for(int j=0;j<n-1;j++)
        {
            cin>>no;
            v1[i].pb(no);
        }
    }

    for(int i=1;i<=n;i++)
    {
        double w=0.0;

        for(int j=0;j<n-1;j++)
        {
            int to= v1[i][j];
            w= distce(i,to);
            v[i].pb(N(to,w));
        }
    }

    dijkstra();

    for(int i=1;i<=n;i++)
    {
        cout<<fixed<<setprecision(6)<<dist[i]<<endl;
    }
}

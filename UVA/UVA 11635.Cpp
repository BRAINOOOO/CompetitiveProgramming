
// ICPC Champion is here

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
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
typedef struct NODE
{
    int no,t,w;
    NODE(int no,int t,int w) : no(no),t(t),w(w) {}

    bool operator < (const NODE &e) const
    {
        return w>e.w;
    }
}N1;
typedef struct NOD
{
    int no,w;
    NOD(int no,int w) : no(no),w(w) {}

    bool operator < (const NOD &e) const
    {
        return w>e.w;
    }
}N2;
int n,vis[10009];
vector< vector<int> > sh(10009);
vector<int> dist(10009);
vector< vector<N2> > v(10009);
vector< vector<N1> > v1(10009);

int dijk(int sr)
{
    for(int i=0;i<10009;i++)
        dist[i]=INT_MAX;
    clr(vis,0);

    priority_queue< N2 > pq;
    pq.push(N2(sr,0));
    dist[sr]=0;

    while(!pq.empty())
    {

       N2 cur= pq.top();
       pq.pop();

       if(vis[cur.no])
        continue;

       vis[cur.no]=1;

       int add= cur.w;

       for(int i=0;i<sz(v[cur.no]);i++)
       {
           N2 nw= v[cur.no][i];


           if(dist[nw.no]>add+nw.w)
           {
               dist[nw.no]= add+nw.w;

               pq.push(N2(nw.no,add+nw.w));

           }
       }
    }
}

int dijk2()
{
    for(int i=0;i<10009;i++)
        dist[i]=INT_MAX;
    clr(vis,0);

    priority_queue< N1 > pq;
    pq.push(N1(1,0,0));
    dist[1]=0;

    while(!pq.empty())
    {

       N1 cur= pq.top();
       pq.pop();
       if(vis[cur.no])
        continue;

       vis[cur.no]=1;

       int add= cur.w;

       for(int i=0;i<sz(v1[cur.no]);i++)
       {
           N1 nw= v1[cur.no][i];

           if(nw.t>600)
            continue;
          int  neww=add;
          int  nwt=cur.t+nw.t;
           if(cur.t+nw.t>600)
           {
               neww=add+1;
               nwt=nw.t;
           }

           if(dist[nw.no]>neww)
           {


               dist[nw.no]=neww;

               pq.push(N1(nw.no,nwt,neww));

           }
       }
    }

    return dist[n];
}
void del()
{
    v1.clear();
    v1.resize(10009);
    v.clear();
    v.resize(10009);
    sh.clear();
    sh.resize(10009);
}



int main()
{

    int h;
   while( cin>>n)
   {
       del();
       if(n==0)
        break;
      cin>>h;
    int H[109];
    h+=2;
    H[0]=1;
    H[1]=n;
    for(int i=2;i<h;i++)
    {
        cin>>H[i];
    }
    int m;
    cin>>m;
    int f,t,w;
    while(m--)
    {
        cin>>f>>t>>w;
        v[f].pb(N2(t,w));
        v[t].pb(N2(f,w));
    }


    for(int i=0;i<h;i++)
    {
        int ho=H[i];
        dijk(ho);
        sh[ho]=dist;
    }


    for(int i=0;i<h;i++)
    {
        for(int j=0;j<h;j++)
        {
            int n1= H[i]; int n2=H[j];

            int w= sh[n1][n2];

            v1[n1].pb(N1(n2,w,0));

        }
    }


      int res= dijk2();
     cout<<( res==INT_MAX ? -1 :res )<<endl;
   }
}


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

typedef struct NOD
{
    int no,w;
    NOD(int no,int w) : no(no),w(w) {}

    bool operator < (const NOD &e) const
    {
        return w>e.w;
    }
}N;
int n,vis[100009];
vector<int> dist(100009);
vector< vector<N> > v;
vector< vector<int> > sh;
int mem[(1<<11)+9][19],s,S[100009];

int  solve(int msk,int preid)
{

     if(msk==(1<<s)-1)
        return sh[0][S[preid]];

      int &ret=mem[msk][preid];

      if(ret!=-1)
        return ret;
      int ans=INT_MAX;
      for(int i=1;i<=s;i++)
      {
          if(getBit(msk,i-1)==1)
            continue;

          int w= sh[S[preid]][S[i]];

          ans=min(ans, w + solve(setBit1(msk,i-1),i));

      }

     return ret=ans;
}







int dijk(int sr)
{
    for(int i=0;i<100009;i++)
        dist[i]=INT_MAX;
    clr(vis,0);

    priority_queue< N > pq;
    pq.push(N(sr,0));
    dist[sr]=0;

    while(!pq.empty())
    {

       N cur= pq.top();
       pq.pop();

       if(vis[cur.no])
        continue;

       vis[cur.no]=1;

       int add= cur.w;

       for(int i=0;i<sz(v[cur.no]);i++)
       {
           N nw= v[cur.no][i];


           if(dist[nw.no]>add+nw.w)
           {
               dist[nw.no]= add+nw.w;

               pq.push(N(nw.no,add+nw.w));

           }
       }
    }
}


void del()
{

    v.clear();
    v.resize(100009);
    sh.clear();
    sh.resize(100009);

}



int main()
{

    int T;
    cin>>T;
   while( T--)
   {
       del();

      cin>>n;

    int m;
    cin>>m;
    int f,t,w;
    while(m--)
    {
        cin>>f>>t>>w;
        v[f].pb(N(t,w));
        v[t].pb(N(f,w));
    }


    cin>>s;
    S[0]=0;
    for(int i=1;i<=s;i++)
    {
         cin>>S[i];
    }

    for(int i=0;i<=s;i++)
    {
         dijk(S[i]);
         sh[S[i]]=dist;
    }
    clr(mem,-1);

   cout<< solve(0,0)<<endl;
   }
}



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
int indeg[100009],vis[100009],A[100009],B[100009],mb[100009];
vector< vector<int> > v(100009);
vector< pair< pair<int,int> ,int> > v1;
vector<int> sol;
int n,m;

int TOPO()
{

    queue<int> q;

    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
            q.push(i);
    }


   while(!q.empty())
   {
       if(sz(q)>1)
        return -1;

       int cur=q.front();
       q.pop();
       sol.pb(cur);



       for(int i=0;i<sz(v[cur]);i++)
       {
           int no= v[cur][i];

           indeg[no]--;

           if(indeg[no]==0)
            q.push(no);

       }
   }
   return 0;
}














int main()
{

    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;

        A[i]=a; B[i]=b;
        indeg[b]++;
        v[a].pb(b);

    }


    int rt=TOPO();

      if(rt==-1)
      {
         cout<<rt<<endl;
         return 0;
      }

      int id=1;
      for(int i=0;i<sz(sol);i++)
      {
          mb[sol[i]]=id++;
      }

      for(int i=0;i<m;i++)
      {
          a=A[i]; b=B[i];

          v1.pb(mp(mp(mb[a],mb[b]),i));
      }

      sort(all(v1));
      int st=-1; int en=-1;
      for(int i=0;i<sz(v1);i++)
      {

          a= v1[i].first.first; b=v1[i].first.second;
         int ed=v1[i].second;
       //  cout<<ed<<endl;
          if(st==-1)
            st=a,en=b,vis[ed]=1;
          else if(b==st)
            st=a,vis[ed]=1;
          else if(a==en)
            en=b,vis[ed]=1;

      }
      int mx=-1;
      for(int i=0;i<m;i++)
      {
          if(vis[i])
          mx=max(mx,i);
      }

      cout<<mx+1<<endl;
}

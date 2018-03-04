/*
explanation : here the idea of the problem it is if i have an edge connecting two nodes one of them the leaf so to cover this edge 
always take the non-leaf node as it have more possiblity of covering more edges but if i take a leaf node it only covers 
exactly one edge, think about this observation and apply it on all the nodes and consider the node that all its edges to its children 
already covered as the leaf node.
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
vector< vector<int> > v(1000009);
set<int> s;
int arr[1000009],vis[1000009];
void dfs(int n)
{
    vis[n]=1;
    for(int i=0;i<sz(v[n]);i++)
    {
        if(vis[v[n][i]])
            continue;
       dfs(v[n][i]);
       if(arr[v[n][i]]==0)
       {
           s.insert(n);
           arr[n]=1;
       }
    }
}
int main()
{
    int n;
    cin>>n;
    int f,t;
    for(int i=1;i<n;i++)
    {
        cin>>f>>t;
        v[f].pb(t);
        v[t].pb(f);
    }
   if(n==1)
   {
       cout<<"1\n";
       return 0;
   }
    dfs(1);
  cout<<sz(s)<<endl;
}

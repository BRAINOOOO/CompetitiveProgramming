/*
explanation : here first you have to know euler formula here is a good link 
https://codingrush.wordpress.com/2012/09/08/faces-of-a-planner-graph/

euler formula is f=e-n+2;
so i need to get the number of nodes for each connected compontent and the number of edges the number of nodes is very easy 
but the number of edges is tricky first the dont pass through cyclic passes so i cant count it the way i count it as nodes
but yu may say just express each edge as the  2 nodes it connects and check if it is visited before or not okay this works
only if there is no multiple edges and this is not the case here so instead of expressing the edge by  the nodes as this way
doesnt make the egde uniqe express it as the nodes plus the number of it in other words it is the first edge moving from node 1 
to node 2 and so on :) but take care edges not directed okay
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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int vis[100],n,v,ed,nodes,f;
vector< vector<pair<int,int>> > arr;
map<char,int> mb;
map< pair<pair<int,int>,int>,int> mb2;
map< pair<int,int> , int > mb3;
void dfs(int n)
{
    if(vis[n])
    {
        return ;
    }
    nodes++;
    vis[n]=1;
    for(int i=0;i<sz(arr[n]);i++)
    {
          if(mb2[mp(mp(n,arr[n][i].first),arr[n][i].second)]==0)
          {
              ed++;
            mb2[mp(mp(n,arr[n][i].first),arr[n][i].second)]=1;
            mb2[mp(mp(arr[n][i].first,n),arr[n][i].second)]=1;
          }
        dfs(arr[n][i].first);
    }
}
int main()
{
   char  ch='a',ch2='A';
    for(int i=0;i<26;i++)
        mb[ch++]=i;
    for(int i=26;i<52;i++)
        mb[ch2++]=i;
   while( cin>>n>>v)
   {
        char c1,c2;
        set<int> s;
        arr.clear();
        arr.resize(100);
        clr(vis,0);
        mb2.clear();
        mb3.clear();
       for(int i=0;i<v;i++)
       {
           cin>>c1>>c2;
          int f=mb[c1];
          int t=mb[c2];
          int u=mb3[mp(f,t)];
          mb3[mp(f,t)]++;
          mb3[mp(t,f)]++;
        arr[f].pb(mp(t,u));
        arr[t].pb(mp(f,u));
        s.insert(t);
        s.insert(f);
       }
       int ans=1,cnt=0;
       for(auto i=s.begin();i!=s.end();i++)
       {
           int num=(*i);
           if(!vis[num])
           {
                nodes=0;
                ed=0;
                f=0;
               dfs(num);
               ans+= ed+2-nodes;
               cnt++;
           }
       }
       ans-=cnt;
       cout<<ans<<endl;
   }
}

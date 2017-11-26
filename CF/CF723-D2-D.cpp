/*
explanation : here the observation is that to reduce the number of lakes so yu need
to block comletetly a lake and to do so it will cost yu all its cells so to minimize
this consider the min number of cells first.

complexity : O( n^2 )
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
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
#define     si         set<int>
#define    oo         900000000000000000
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
const int MAX=50+9;
int vis[MAX][MAX],flag,cnt,n,m;
vs v;
void dfs(int r,int c)
{
    if(r==n||c==m||r<0||c<0||vis[r][c]||v[r][c]=='*')
        return ;
    if(r==n-1||r==0||c==m-1||c==0)
    {
        flag=0;
    }
    vis[r][c]=1;
    cnt++;
    dfs(r+1,c);
    dfs(r,c+1);
    dfs(r-1,c);
    dfs(r,c-1);
}
void dfsupdate(int r,int c)
{
    if(r==n||c==m||r<0||c<0||vis[r][c]||v[r][c]=='*')
        return ;
    vis[r][c]=1;
    v[r][c]='*';
    dfsupdate(r+1,c);
    dfsupdate(r,c+1);
    dfsupdate(r-1,c);
    dfsupdate(r,c-1);
}
int main()
{
    int k;
    cin>>n>>m>>k;
    string st;
    for(int i=0;i<n;i++)
    {
        cin>>st;
        v.pb(st);
    }
  vector< pair<int,pi > > v1;
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
          flag=1;
          cnt=0;
          dfs(i,j);
          if(flag&&cnt>0)
            v1.pb(mp(cnt,mp(i,j)));
      }
  }
  sort(all(v1));
  int cost=0;
  int need=sz(v1)-k;
  for(int i=0;i<sz(v1)&&need>0;i++)
  {
    cost+=v1[i].first;
    int  r=v1[i].second.first;
    int  c=v1[i].second.second;
      need--;
      clr(vis,0);
      dfsupdate(r,c);
  }
  cout<< cost<<endl;
  for(int i=0;i<n;i++)
    cout<<v[i]<<endl;
}
/*
Cases
6 6 1
****..
*.*...
*...*.
***.**
**.***
*..*.*
*/

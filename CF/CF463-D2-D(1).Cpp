/*
explanation : here first try to think for a simple ex 1 2 3 4   A
                                                      2 3 1 4   B
                                         if ai comes before aj and there is bi == ai and bj == aj , i<j
                                         so common subsequence could be ai aj , okay from here i will build
                                         a directed graph which connects the numbers i -----> j , and by getting
                                         the longest path the problem will be solved.
  
complexity : o( n^2*k ) 
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
int vis[1000+9],n,k,mx;
int arr[1000+9][1000+9],best[1000+9];
vector<int > e[1000+9];
void dfs(int id)
{
    if(vis[id])
        return ;
    vis[id]=1;
    for(int i=0;i<sz(e[id]);i++)
    {
        dfs(e[id][i]);
        best[id]=max(best[id],best[e[id][i]]+1);
    }
    best[id]=max(best[id],1);
    mx=max(mx,best[id]);
}
int main()
{
    cin>>n>>k;
    int no;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>no;
            arr[i][no]=j;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            bool ok=1;
            for(int l=0;l<k;l++)
            {
               if( arr[l][i]>arr[l][j] )
                ok=0;
            }
            if(ok)
                e[i].pb(j);
        }
    }
    mx=1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
  cout<<mx;
}

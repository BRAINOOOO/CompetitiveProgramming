/*
explanation : here the idea is if i assumed that i will start from node A and end at node Z every edge will be visited twice
except for the edges of the path from start A to end Z and to minmize i need this path to be max so i will get tree diameter
i know its a tree bec he say that between each 2 nodes there is a unique path.

complexity : nlogn*T .
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
int vis[10000+9],mx,node;
vector< vector<int> > v;
int dfs(int n,int l)
{
    vis[n]=1;
    int cnt=0;
    for(int i=0;i<sz(v[n]);i++)
    {
        if(vis[v[n][i]])
            continue;
        cnt++,dfs(v[n][i],l+1);
    }
    if(cnt==0)
    {
        if(l>mx)
        {
            mx=l;
            node=n;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m,no;
        v.clear();
        v.resize(10000+9);
        for(int i=1;i<=n;i++)
        {
            cin>>m;
            for(int j=0;j<m;j++)
            {
                cin>>no;
                v[i].pb(no);
            }
        }
          clr(vis,0);
            mx=0;
            dfs(1,0);
            mx=0;
            clr(vis,0);
            dfs(node,0);
        cout<<mx+(n-1-mx)*2<<endl;
    }
}

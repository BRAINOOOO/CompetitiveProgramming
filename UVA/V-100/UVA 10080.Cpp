/*
the idea is to get the max matching
*/

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
#define     point                    complex<long double>
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
int v[205][205],path[205],vis[205],pathlen,S,T,s,vl;
pair<double,double> lf[205],rg[205];
int dfs(int s,int d,int l,int m)
{
    path[l]=s;
    if(s==d)
    {
        pathlen=l+1;
        return m;
    }
    int ret=0;
    vis[s]=1;
    for(int i=0;i<=T;i++)
    {
        if(vis[i]||v[s][i]<=0)
            continue;


        ret=dfs(i,d,l+1,min(m,v[s][i]));
        if(ret>0)
            return ret;

    }
    return ret;
}
int MaxFlow()
{
    int flows=0;
    while(1)
    {
        clr(vis,0);
        int fl=dfs(S,T,0,INT_MAX);
        if(fl==0)
            break;
        for(int i=1;i<pathlen;i++)
        {
            int fr=path[i-1]; int to=path[i];
            v[fr][to]-=fl;
            v[to][fr]+=fl;
        }
        flows+=fl;
    }
    return flows;
}
bool check(pair<double,double> a,pair<double,double> b)
{
    double d=sqrt((b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second));
    d/=vl;
    if(dcmp(s,d)!=-1)
        return 1;
    return 0;
}
int main()
{
    int n,m;
    while(cin>>n>>m>>s>>vl)
    {
        clr(v,0);
        double x,y;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
            lf[i]=mp(x,y);
        }
         for(int i=1;i<=m;i++)
        {
            cin>>x>>y;
            rg[i]=mp(x,y);
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(check(lf[i],rg[j]))
                    v[i][n+j]=1;
            }
        }
        S=0; T=n+m+1;
        for(int i=1;i<=n;i++)
            v[S][i]=1;
        for(int i=1;i<=m;i++)
            v[i+n][T]=1;
       cout<< m-MaxFlow()<<endl;
    }
}




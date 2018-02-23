/*
explanation : here it is stright forward on topological sort 
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
stack<int> st;
int n,k,vis[100000+9],par[100000+9];
vector< vector<int> > v(100000+9);
void topol(int n)
{
    vis[n]=1;
    for(int i=0;i<sz(v[n]);i++)
    {
       int c= v[n][i] ;
        if(vis[c])
            continue;
        topol(v[n][i]);
    }
    st.push(n);
}
int main()
{
    scanf("%d %d",&n,&k);
    int w,no;
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&w);
        for(int j=0;j<w;j++)
        {
            scanf("%d",&no);
            v[i].pb(no);
        }
    }
    for(int i=1;i<=k;i++)
    {
        if(!vis[i])
        {
           topol(i);
        }
    }
    int pre=0,root;
    if(!st.empty())
        root=st.top();
    while(!st.empty())
    {
        int cur=st.top();
        st.pop();
        par[cur]=pre;
        pre=cur;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            par[i]=root;
    }
   for(int i=1;i<=n;i++)
   {
       printf("%d\n",par[i]);
   }
}

/*
explanation : the idea is very simple expection is the length till i stop multiplied by the probability of that length let it
be p(L) how it can be calculated at each move the probability of choosing a certain child to move to is 1/(total number of children)
but take care it is undirected edges so number of children should be subracted by 1 except for the root .
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
int n,vis[100000+9];
double res=0.0;
vector< vector<int> > v(100000+9);
void  dfs(int n,int l,double p)
{
    if((sz(v[n])==1&&n!=1)||(sz(v[n])==0&&n==1))
    {
        res+= l*p;
        return ;
    }
    vis[n]=1;
    for(int i=0;i<sz(v[n]);i++)
    {
        if(vis[v[n][i]])
            continue;
       int len= sz(v[n])+(n==1 ? 0 : -1);
        dfs(v[n][i],l+1,p*(1.0/len));
    }
}
int main()
{
    cin>>n;
    int f,t;
    for(int i=0;i<n-1;i++)
    {
        cin>>f>>t;
        v[f].pb(t);
        v[t].pb(f);
    }
    dfs(1,0,1.0);
    cout<<fixed<<setprecision(10)<<res<<endl;
}

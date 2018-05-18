/*
 consider the A modes as the left part of a bipartite graph and the B modes the other side
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
int v[109][209],vis[209],n,lf[209],rg[209];
int canmatch(int i)
{
    for(int j=0;j<209;j++)
    {
        if(vis[j]||v[i][j]==0)
            continue;
        vis[j]=1;
        if(lf[j]==-1||canmatch(lf[j]))
        {
            lf[j]=i; rg[i]=j;
            return 1;
        }
    }
    return 0;
}
int Bipart()
{
    int flows=0;
    clr(lf,-1);
    clr(rg,-1);
    for(int i=0;i<n;i++)
    {
        clr(vis,0);
       if(canmatch(i))
            flows++;
    }
    return flows;
}
int main()
{

    while(cin>>n)
    {
        if(!n)
            break;
        clr(v,0);
        int m,k;
        cin>>m>>k;
        int I,fr,to;
        for(int i=0;i<k;i++)
        {
            cin>>I>>fr>>to;
            if(fr==0||to==0)
                continue;
            v[fr][to+n]=1;
        }

        cout<<Bipart()<<endl;
    }
}

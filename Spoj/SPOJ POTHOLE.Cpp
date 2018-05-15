/*
simply every all the edges from source needed to be traversed once and the same for the edges to the end so put a capacity of one 
and the other edges there is no limit
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
int n,v[209][209],vis[209],path[209],pathlen;
int dfs(int sr,int des,int len,int mi)
{
    path[len]=sr;
    if(sr==des)
    {
        pathlen=len+1;
        return mi;
    }
    vis[sr]=1;
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]||v[sr][i]<=0)
            continue;
        ret=dfs(i,des,len+1,min(mi,v[sr][i]));
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
        int fl=dfs(1,n,0,INT_MAX);
        if(!fl)
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
 
int main()
{
 
    int T;
    cin>>T;
 
    while(T--)
    {
 
       cin>>n;
       int no,num;
       clr(v,0);
       for(int i=1;i<=n-1;i++)
       {
           cin>>no;
           for(int j=0;j<no;j++)
           {
               cin>>num;
               if(i==1)
                v[i][num]=1;
               else if(num==n)
                v[i][num]=1;
               else
                v[i][num]=INT_MAX;
           }
       }
 
      cout<< MaxFlow()<<endl;
    }
}
 

#include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<map>
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
const double eps= (1e-5);
using namespace std;
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int v[109][109],vis[109],pathlen,path[109];

int dfs(int S,int T,int len,int mi)
{
    path[len]=S;
    if(S==T)
    {
        pathlen=len;
        return mi;
    }
    vis[S]=1;
    for(int i=1;i<109;i++)
    {
        if(vis[i]||v[S][i]<=0)
            continue;
       int val= dfs(i,T,len+1,min(mi,v[S][i]));
       if(val>0)
        return val;
    }

    return 0;
}















int MaxFlow(int S,int T)
{
    int flows=0;

    while(1)
    {
       clr(vis,0);
       int val=dfs(S,T,0,INT_MAX);
       if(!val)
        break;

       for(int i=1;i<=pathlen;i++)
       {
          int f=path[i-1]; int t=path[i];
           v[f][t]-=val;
           v[t][f]+=val;
       }
      flows+=val;
    }
    return flows;
}


int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        if(!n&&!m)
            break;
        clr(v,0);
        int id,val;
        for(int i=0;i<n-2;i++)
        {
            cin>>id>>val;
            v[id][n+id]=val;
            v[n+id][id]=val;
        }
        v[1][1+n]=INT_MAX;
        v[1+n][1]=INT_MAX;
        v[n+n][n]=INT_MAX;
        v[n][n+n]=INT_MAX;
        int f,t,w;
        for(int i=0;i<m;i++)
        {
            cin>>f>>t>>w;

             v[f+n][t]=w;
             v[t+n][f]=w;



        }

        cout<<MaxFlow(1,n)<<endl;
    }
}








// ICPC champion is here
#include <bits/stdc++.h>
#include<iostream>
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
const ll MAX=200;
int com[MAX],v[MAX][MAX],vis[MAX],vis2[MAX];
vector<vector<int>> comp;
vector<pair<int,int> > e;

void SCC(int n)
{

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(v[i][k]&&v[k][j])
                    v[i][j]=1;
            }
        }
    }

    int cnt=0;
    clr(com,-1);
    for(int i=1;i<=n;i++)
    {
        if(com[i]==-1)
         {
              com[i]=cnt;
              comp.pb(vector<int>());
              comp.back().pb(i);
              cnt++;
         }

        for(int j=i+1;j<=n;j++)
        {
            if(v[i][j]&&v[j][i])
             {
                 com[j]=com[i];
                 comp[com[j]].pb(j);
             }
        }
    }
}
void dfs2(int n,int N)
{
    vis2[n]=1;
    for(int i=1;i<=N;i++)
    {
        if(!vis2[i]&&v[n][i]==1)
            dfs2(i,N);
    }
}



class  CarrotBoxes
{
public :

     double theProbability(vector <string> inf)
     {



        int n=sz(inf);
         for(int i=1;i<=n;i++)
            v[i][i]=1;
         for(int i=0;i<sz(inf);i++)
         {
             for(int j=0;j<sz(inf[i]);j++)
             {
                 if(inf[i][j]=='Y')
                 {
                      v[i+1][j+1]=1;
                      e.pb(mp(i+1,j+1));
                 }
             }
         }

         SCC(n);
        vector<int> top;

         for(int i=0;i<sz(e);i++)
         {
             int fr=e[i].first; int to=e[i].second;

             if(com[fr]!=com[to])
             {

                 vis[com[to]]=1;
             }
         }

         for(int i=0;i<sz(comp);i++)
            if(vis[i]==0)
             top.pb(comp[i][0]);



         for(int i=0;i<sz(top);i++)
         {
            int lastone=top[i];

            clr(vis2,0);

            for(int l=0;l<sz(top);l++)
            {
                 if(l!=i)
                dfs2(top[l],n);
            }

         int fl=0;

         for(int i=1;i<=n&&!fl;i++)
            if(vis2[i]==0&&i!=lastone)
              fl=1;

         if(!fl)
         {
             //cout<<"yes";

          return (1.0-((sz(top)-1.0)/n));
         }
         }

         return (1.0-((sz(top)+0.0)/n));


     }


};


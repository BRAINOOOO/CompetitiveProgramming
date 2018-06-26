/*
the idea is imagine that every bank is a source and the out of grid is to a tank so i want max outing.
*/
// ICPC champion is here
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
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int add=2500,s,a,b,mb[59][59],in[3000*2],v[2509*2][2509*2],path[3000*2],vis[3000*2];
int inf=1000000,pathlen;
int dfs(int S,int E,int cnt,int mi)
{
   //cout<<S<<endl;
    path[cnt]=S;
    if(S==E)
    {
      //cout<<"in";
        pathlen=cnt;
        return mi;
    }
    vis[S]=1;
    int ret=0;
    for(int i=0;i<=E+2;i++)
    {
        if(v[S][i]>0&&!vis[i])
        {

             ret= dfs(i,E,cnt+1,min(mi,v[S][i]));
            if(ret>0)
                break;
        }
    }
    return ret;
}




int MaxFlow(int S,int E)
{


    int flows=0;


    while(1)
    {

       clr(vis,0);
      int havepath= dfs(S,E,0,INT_MAX);

      if(!havepath)
        break;

      for(int i=1;i<=pathlen;i++)
      {
          int fr=path[i-1];
          int to=path[i];

          v[fr][to]-= havepath;
          v[to][fr]+= havepath;
      }
    flows+= havepath;
    }

    return flows;
}
















int main()
{
   int T;
   cin>>T;
   while(T--)
   {

       cin>>a>>s>>b;
       clr(v,0);



    int id=1;

    for(int i=1;i<=s;i++)
    {
        for(int j=1;j<=a;j++)
        {
            mb[i][j]=id++;
            in[mb[i][j]]=mb[i][j]+add;
            v[in[mb[i][j]]][mb[i][j]]=1;
        }
    }

    for(int i=1;i<=s;i++)
    {
        for(int j=1;j<=a;j++)
        {
            int fr=mb[i][j],to;
            if(j+1<=a)
            {
                to=in[mb[i][j+1]];
                v[fr][to]=inf;
            }
            if(i+1<=s)
            {
                to=in[mb[i+1][j]];
                v[fr][to]=inf;
            }
            if(j-1>=1)
            {
                to=in[mb[i][j-1]];
                v[fr][to]=inf;
            }
            if(i-1>=1)
            {
                to=in[mb[i-1][j]];
                v[fr][to]=inf;
            }
        }
    }
    int S=0;
    int E=2500*2+9;
    int r,c;

    for(int i=1;i<=b;i++)
    {
        cin>>c>>r;
        r= s-r+1;
        int to= in[mb[r][c]];
        v[S][to]=1;

    }
    for(int i=1;i<=s;i++)
    {
        c=1;
        r=i;
        int fr= mb[r][c];
        v[fr][E]=1;
    }
    for(int i=1;i<=s;i++)
    {
        c=a;
        r=i;
        int fr= mb[r][c];
        v[fr][E]=1;
    }
    for(int i=1;i<=a;i++)
    {
        c=i;
        r=1;
        int fr= mb[r][c];
        v[fr][E]=1;
    }
    for(int i=1;i<=a;i++)
    {
        c=i;
        r=s;
        int fr= mb[r][c];
        v[fr][E]=1;
    }


    int res=MaxFlow(S,E);

    if(res==b)
        cout<<"possible\n";
    else
        cout<<"not possible\n";

   }
}








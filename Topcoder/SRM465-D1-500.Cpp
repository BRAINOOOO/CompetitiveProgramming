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
int n,m,vis[152],Cost,L,path[152],Mindtoplant[150],Mindtobase[150],arr[152][152];
int inf=100000000;
ll dfs(int no,int des,int len,int mi)
{
    path[len]=no;
    vis[no]=1;
    if(no==des)
    {
        L=len;
        return mi;
    }
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]||arr[no][i]<=0)
            continue;

      ret= dfs(i,des,len+1,min(mi,arr[no][i]));

       if(ret>0)
        return ret;
    }

    return ret;
}




int MaxFlow(int src,int sink)
{
    int ans=0;
    while(1)
    {

    clr(vis,0);
    Cost=dfs(src,sink,0,INT_MAX);
    if(!Cost)
        break;
    for(int i=0;i<L;i++)
    {
        int fr= path[i];
        int to= path[i+1];

        arr[fr][to]-=Cost;
        arr[to][fr]+=Cost;

    }

      ans+=Cost;
    }

    return ans;
}

int dist(int x1,int y1,int x2,int y2)
{
    return (y2-y1)*(y2-y1)+(x2-x1)*(x2-x1);
}

class  GreenWarfare
{
public :


int minimumEnergyCost(vector <int> canonX, vector <int> canonY, vector <int> baseX, vector <int> baseY, vector <int> plantX, vector <int> plantY, int energySupplyRadius)
{



    for(int i=0;i<sz(baseX);i++)
    {
        int mi=INT_MAX;
        for(int j=0;j<sz(canonX);j++)
        {
            mi=min(dist(baseX[i],baseY[i],canonX[j],canonY[j]),mi);
        }

        Mindtobase[i]=mi;
    }

    for(int i=0;i<sz(plantX);i++)
    {
        int mi=inf;
        for(int j=0;j<sz(canonX);j++)
        {
            mi=min(dist(plantX[i],plantY[i],canonX[j],canonY[j]),mi);
        }

        Mindtoplant[i]=mi;
    }

    int S=1;
    int T=sz(baseX)+sz(plantX)+3;
    int id=sz(baseX)+2;
    for(int i=0;i<sz(baseX);i++)
    {
        arr[S][i+2]=Mindtobase[i];

        for(int j=0;j<sz(plantX);j++)
        {
            if(dist(baseX[i],baseY[i],plantX[j],plantY[j])<=energySupplyRadius)
                arr[i+2][id+j]=inf;
        }
    }

    for(int i=0;i<sz(plantX);i++)
    {
        arr[id+i][T]=Mindtoplant[i];
    }

    return MaxFlow(S,T);

  }
};



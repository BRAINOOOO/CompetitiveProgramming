/*
put weights on vertexes with one bec we need a vertex-disjoint path and it will be egde disjoint too.
the idea is i will put a super node X on a and c if the maxflow from X to b equals to exactly 2 so there is a path else NO
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
int vis[30011*2+10000],path[30011*2+10000],pathlen,n;
vector< vector<pair<int,int> > > v;
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
    for(int  i=0;i<sz(v[sr]);i++)
    {
        int no=v[sr][i].first;
        int w=v[sr][i].second;
        if(vis[no]||w<=0)
            continue;
        ret=dfs(no,des,len+1,min(mi,w));
        if(ret>0)
            return ret;
    }
    return ret;
}

int MaxFlow(int sr,int des)
{
    int flows=0;
    while(1)
    {
        clr(vis,0);
        int fl=dfs(sr,des,0,INT_MAX);

        if(!fl)
            break;

        for(int i=1;i<pathlen;i++)
        {
            int fr=path[i-1]; int to=path[i];

            for(int j=0;j<sz(v[fr]);j++)
            {
                if(v[fr][j].first==to)
                {
                    v[fr][j].second-=fl;
                    break;
                }
            }
            int flag=0;
            for(int j=0;j<sz(v[to]);j++)
            {
                if(v[to][j].first==fr)
                {
                    v[to][j].second+=fl;
                    flag=1;
                    break;
                }
            }
            if(!flag)
                v[to].pb(mp(fr,fl));
        }


         flows+=fl;
    }
    return flows;
}

int main()
{
    int T;
   scanf("%d",&T);

    while(T--)
    {
        v.clear();

        int m;
       scanf("%d %d",&n,&m);
       v.resize(n*10+9);
       int fr,to;
       for(int i=2;i<(n+1)*2;i+=2)
       {
           v[i].pb(mp(i+1,1));

       }
       for(int i=0;i<m;i++)
       {
           scanf("%d %d",&fr,&to);
           if(fr>30011 || to>30011 || fr<=0 || to <=0 ) continue;
           v[fr*2+1].pb(mp(to*2,1));
           v[to*2+1].pb(mp(fr*2,1));


       }

       v[1].pb(mp(3*2,1));
       v[1].pb(mp(1*2,1));



       int res=MaxFlow(1,2*2);
       if(res==2)
        printf("YES\n");
       else
        printf("NO\n");
    }
}




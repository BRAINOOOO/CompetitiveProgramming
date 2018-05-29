/*
the idea is that the disjoint graphs needed always to build a station at the min cost node 
there is two things
1- how could i get the disjoint graph, well by getting the SCCs and check if there is an edge connecting 2 different components
2- if i get the nessary cost to build the stations i can build other ones i don't need them to min the total Average but the value
must be less than the Average ( try to prove it mathematically )
*/


// ICPC Champion is here

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
const ll MAX=1000009;
int arr[100],Taken[100],arr2[100];
vector<vector<int>> v(MAX),comp;
int dfsN[MAX],lowlink[MAX],instack[MAX],F=1,com[MAX],vis[MAX];
vector<pair<int,int>> e;
stack<int> st;
void dfs(int n)
{
    dfsN[n]=lowlink[n]=F++;
    st.push(n);
    instack[n]=1;

    for(int i=0;i<sz(v[n]);i++)
    {
        int no=v[n][i];
        if(dfsN[no]==0)
        {
            dfs(no);
            lowlink[n]=min(lowlink[no],lowlink[n]);
        }
        else if(instack[no]==1)
        {
            lowlink[n]=min(lowlink[no],lowlink[n]);
        }
    }

    if(lowlink[n]==dfsN[n])
    {
        int x=-1;
        comp.pb(vector<int>());
        while(x!=n)
        {
            x=st.top(); st.pop();
            comp.back().pb(x);
            instack[x]=0;
            com[x]=sz(comp)-1;
        }
    }

}







class 	AntarcticaPolice
{
public:

    double minAverageCost(vector<int> cost, vector<string> roads)
    {
         //cerr<<"in";

        int n=sz(roads);
        for(int i=0;i<sz(roads);i++)
        {
            int f=i+1;
            for(int j=0;j<sz(roads[i]);j++)
            {
                if(roads[i][j]=='Y')
                {
                    e.pb(mp(f,j+1));
                   v[f].pb(j+1);
                }

            }
        }
    //cout<<"in";
        for(int i=1;i<=n;i++)
        {
            if(dfsN[i]==0)
                dfs(i);
        }
       // cout<<"in";
        int id=0;

        multiset<int> s;
        for(int i=0;i<sz(comp);i++)
        {
            int mi=INT_MAX;
            for(int j=0;j<sz(comp[i]);j++)
            {
                int no=comp[i][j];
                if(cost[no-1]<mi)
                {
                    mi=cost[no-1];
                    id=no;
                }
            }
            arr[i]=mi;
            s.insert(mi);
            Taken[id]=1;
            arr2[i]=id;
        }

        for(int i=0;i<sz(e);i++)
        {
            int fr=e[i].first; int to=e[i].second;
            if(com[fr]!=com[to]&&vis[com[to]]==0)
            {
                s.erase(s.find(arr[com[to]]));
                vis[com[to]]=1;
                Taken[arr2[com[to]]]=0;
            }
        }
        int sum=0;
        for(auto it=s.begin();it!=s.end();it++)
            sum+=(*it);
       double AV=sum/(sz(s)+0.0);
      // cout<<sz(s)<<endl;
       int siz=sz(s);
       while(1)
       {
           int mi=INT_MAX,No;
           for(int i=1;i<=n;i++)
           {
               if(Taken[i]==0)
               {
                   if(cost[i-1]<mi)
                   {
                       mi=cost[i-1];
                       No=i;
                   }
               }
           }
           if(mi<AV)
           {
               AV=(sum+mi)/(siz+1+0.0);
               sum+=mi;
               siz+=1;
               Taken[No]=1;
           }
           else
            break;

       }

        return AV;
    }
};





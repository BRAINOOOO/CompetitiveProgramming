/*
get the SCCs and check if an edge goes from one component to other one so reduce the answer by one bec the push can transfer to all this
component
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
vector<vector<int>> v,comp;
const ll MAX=1000009;
int dfsN[MAX],lowlink[MAX],instack[MAX],F,com[MAX],vis[MAX];
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






void I()
{
    v.clear();
    v.resize(MAX);
    comp.clear();
    clr(dfsN,0);
    clr(instack,0);
    clr(lowlink,0);
    clr(com,0);
    e.clear();
    clr(vis,0);
     F=1;
}
int main()
{

    int T;
    cin>>T;

    while(T--)
    {
        I();
        int n,m;
        cin>>n>>m;
        int f,t;
        for(int i=0;i<m;i++)
        {
            cin>>f>>t;
            v[f].pb(t);
            e.pb(mp(f,t));
        }

       for(int i=1;i<=n;i++)
        if(dfsN[i]==0)
         dfs(i);
        int ans=sz(comp);
        for(int i=0;i<sz(e);i++)
        {
            f=e[i].first; t=e[i].second;

            if(com[f]!=com[t]&&!vis[com[t]])
            {
                ans--;
                vis[com[t]]=1;
            }
        }
         cout<<ans<<endl;
    }
}


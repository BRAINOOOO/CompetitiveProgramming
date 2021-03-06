/*
the idea is that sinks are the disjoint SCCs why ? bec if there is an edge between two SCCs so every node in the 1st componet will reach 
every node in the second one but since it doesn't belong to the same component so the nodes in the second one won't reach the nodes in 
the first one so all the nodes in the first one aren't sinks, just try to get relations between the different SCCs :)
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
int F=1;
vector<vector<int> > comp;
vector< vector<int> > v(10009);
int lowlink[1000009],dfsN[10009],instack[10009],com[10009],No[10009];
vector<pair<int,int> > e;
stack<int> st;
vector<int> ans;
void dfs(int n)
{


    instack[n]=1;
    lowlink[n]=F;
    dfsN[n]=F++;
    st.push(n);
    for(int i=0;i<sz(v[n]);i++)
    {
        int no=v[n][i];
        if(dfsN[no]==0)
        {
            dfs(no);
            lowlink[n]=min(lowlink[n],lowlink[no]);
        }
        else if(instack[no])
        {

            lowlink[n]=min(lowlink[n],lowlink[no]);

        }
    }

    if(lowlink[n]==dfsN[n])
    {
        int x=-1;
        comp.pb(vector<int>());
        while(x!=n)
        {
            x=st.top();
            st.pop();
            comp.back().pb(x);
            instack[x]=0;
            com[x]=sz(comp)-1;
        }

    }
}

void CLR()
{
    ans.clear();
    clr(lowlink,0);
    clr(No,0);
    clr(dfsN,0);
    clr(com,0);
    v.clear();
    v.resize(1000009);
    clr(instack,0);
    e.clear();
    comp.clear();
    F=1;

}










int main()
{
    int n,m;
    while(scanf("%d",&n)==1)
   {
       if(n==0)
        break;
       scanf("%d",&m);
       CLR();
    int fr,to;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&fr,&to);
        v[fr].pb(to);
        e.pb(mp(fr,to));
    }
    for(int i=1;i<=n;i++)
    {
        if(dfsN[i]==0)
         dfs(i);
    }
     for(int i=0;i<m;i++)
     {
         fr=e[i].first;
         to=e[i].second;

         if(com[to]!=com[fr])
            No[com[fr]]=1;

     }

    for(int i=0;i<sz(comp);i++)
    {
        if(!No[i])
        {
            for(int j=0;j<sz(comp[i]);j++)
                ans.pb(comp[i][j]);
        }
    }
    sort(all(ans));
    for(int i=0;i<sz(ans);i++)
        cout<<ans[i]<<" ";
    printf("\n");
   }
}


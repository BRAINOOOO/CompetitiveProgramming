/*
algo used : SCC by tarjan
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
int dfsN[2009],lowlink[2009],instack[2009];
vector<vector<int>> v,comp;
int F=1;
stack<int> st;
void dfs(int n)
{

    dfsN[n]=lowlink[n]=F++;
    instack[n]=1;
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
        if(dfsN[n]==lowlink[n])
        {


           int x=-1;
           comp.pb(vector<int>());
           while(x!=n)
           {
               x=st.top();
               st.pop();
               comp.back().pb(x);
               instack[x]=0;
           }
        }
}
















void I()
{
    v.clear();
    v.resize(2009);
    clr(dfsN,0);
    clr(lowlink,0);
    comp.clear();
    F=1;
    clr(instack,0);
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
        while(1)
        {
            cin>>f;
            if(f==0||f==-1)
                break;
            cin>>t;

            v[f].pb(t);
        }

        for(int i=1;i<=n;i++)
            if(dfsN[i]==0)
             dfs(i);

        cout<<sz(comp)<<endl;
    }
}








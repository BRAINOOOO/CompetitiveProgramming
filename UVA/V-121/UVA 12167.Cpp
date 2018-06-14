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
#define     point                    complex<long double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
//int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const int MAX=20009;
vector< vector<int> > v,comp,v1;
int instack[MAX],lowlink[MAX],dfsN[MAX],F,com[MAX],inn[MAX],out[MAX];
set<int> stt;
stack<int> st;
vector< pair<int,int> > e;
void I()
{
    clr(instack,0);
    clr(lowlink,0);
    clr(dfsN,0);
    F=1;
    clr(com,0);

    v.clear();
    v.resize(MAX);

    comp.clear();
    clr(inn,-1);
    clr(out,-1);
    e.clear();
}
void dfs(int no)
{

    dfsN[no]=lowlink[no]=F++;
    instack[no]=1;
    st.push(no);



   for(int i=0;i<sz(v[no]);i++)
   {
       int nw=v[no][i];

       if(dfsN[nw]==0)
       {
           dfs(nw);
           lowlink[no]=min(lowlink[no],lowlink[nw]);
       }
       else if(instack[nw])
       {
           lowlink[no]=min(lowlink[no],lowlink[nw]);
       }
   }

   if(lowlink[no]==dfsN[no])
   {
       comp.pb(vector<int>());
       int x=-1;
       while(x!=no)
       {
           x=st.top(); st.pop();
           instack[x]=0;
           comp.back().pb(x);
           com[x]=sz(comp)-1;


       }


   }
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
       int f,to;
       for(int i=0;i<m;i++)
       {
           cin>>f>>to;

           v[f].pb(to);

           e.pb(mp(f,to));
       }

      for(int i=1;i<=n;i++)
      {
          if(dfsN[i]==0)
            dfs(i);
      }
    for(int i=0;i<sz(comp);i++)
     {
        inn[i]=0;
        out[i]=0;
     }

     for(int i=0;i<sz(e);i++)
     {
         f=e[i].first;
         to=e[i].second;

         if(com[f]!=com[to])
         {
            int fr=comp[com[f]][0];
            int too= comp[com[to]][0];
              inn[com[to]]=1 ;
              out[com[f]]=1;

         }
     }
     int in=0,ot=0;
     for(int i=0;i<sz(comp);i++)
        if(inn[i]==0)
          in++;
        if(out[i]==0)
            ot++;


    if(sz(comp)==1)
        cout<<"0\n";
    else
 cout<<max(in,ot)<<endl;
    }
}




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
//void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int dfsN[100009],lowlink[100009],instack[100009];
vector<vector<int>> v(100009),comp;
int F=1;
stack<int> st;
ll cost[100009],M=1e9+7;
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

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>cost[i];
    }
   int m;
   cin>>m;
   int fr,to;
   for(int i=0;i<m;i++)
   {
       cin>>fr>>to;
       v[fr].pb(to);
   }
   for(int i=1;i<=n;i++)
    if(dfsN[i]==0)
     dfs(i);
   ll ans2=1,ans1=0;
   for(int i=0;i<sz(comp);i++)
   {
       ll cnt=0,mi=1e10;
       for(int j=0;j<sz(comp[i]);j++)
       {
           int no=comp[i][j];

           if(cost[no]<mi)
           {
               cnt=1;
           }
           else if(cost[no]==mi)
            cnt++;

          mi=min(mi,cost[no]);

       }

       ans2=(ans2*cnt)%M;
       ans1+=mi;
   }
   cout<<ans1<<" "<<ans2<<endl;
}






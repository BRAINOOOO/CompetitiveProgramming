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
ll mem[(1<<20)][2],inf=(1ll<<62);
int m,k,n,b;
int MSK[101];
typedef struct NODE
{
   ll x,k,m;
   vector<ll> V;

    NODE(ll mx,ll mk,ll mm,vector<ll> mV)
    {
        x=mx; k=mk; m=mm; V=mV;
    }

    bool operator < (const NODE &e) const
    {
        return k>e.k;
    }
}N;
vector< N > v;























int main()
{
   // M();

    cin>>n>>m>>b;
    ll x,k,MM;
    for(int i=0;i<n;i++)
    {
        cin>>x>>k>>MM;
        vector<ll> v1;
        ll no;
        for(int j=0;j<MM;j++)
        {
            cin>>no;
            v1.pb(no);
        }
        v.pb(N(x,k,MM,v1));

    }

    sort(all(v));


    for(int i=0;i<sz(v);i++)
    {
        //cout<<v[i].k<<endl;
        vector<ll> &vv=v[i].V;
        int sk=0;
        for(int j=0;j<sz(vv);j++)
        {
            vv[j]-=1;
            sk=setBit1(sk,vv[j]);
        }
        MSK[i]=sk;
    }
   for(int i=0;i<(1<<20);i++)
    mem[i][0]=mem[i][1]=inf;

   //mem[0]=0;

   ll mi=inf;
 for(int j=0;j<n;j++)
{
   for(int i=0;i<(1<<m);i++)
   {



          if(i==0)
          {
              ll cost= v[j].x+v[j].k*b;
              cout<<cost<<" "<<mem[i|MSK[j]][0]<<endl;
               mem[i|MSK[j]][0]=min(mem[i|MSK[j]][0],cost);

               if((i|MSK[j])==(1<<m)-1)
                mi=min(cost,mi);

          }
          else
          {
              ll cost= v[j].x;

              ll c=min(mem[i][0],mem[i][1]);

              if((i|MSK[j])==(1<<m)-1)
                mi=min(c+cost,mi);

              mem[i|MSK[j]][1]=min(mem[i|MSK[j]][1],c+cost);
          }
      }
   }





   ll res;
   res=mi;
   cout<<(res==inf? -1:res)<<endl;
}



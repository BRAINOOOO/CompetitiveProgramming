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
int mem[1009][1009],par[1009],rnk[1009],W[1009],B[1009],sum[1009],be[1009];
vector< vector<int> > v(1009);
vector<int> v1;
int solve(int id,int w)
{
   if(id==sz(v1))
        return 0;

  int &ret=mem[id][w];
  if(ret!=-1)
    return ret;
  int no=v1[id],p1=0,p2=0,p3=0;

  if(sz(v[no])==1)
  {
      if(W[no]<=w)
     p1=B[no]+ solve(id+1,w-W[no]);

     p2= solve(id+1,w);

  }
  else
  {

      for(int i=0;i<sz(v[no]);i++)
      {
          int nw=v[no][i];

          if(W[nw]<=w)
            p1=max(p1,B[nw]+ solve(id+1,w-W[nw]));
      }
      if(sum[no]<=w)
      p3= be[no]+solve(id+1,w-sum[no]);

      p2= solve(id+1,w);
  }

  return ret=max(p1,max(p2,p3));


}













void I(int n)
{
    for(int i=1;i<=n;i++)
        par[i]=i,rnk[i]=1;
}
int getpar(int n)
{
    if(par[n]==n)
        return n;
    return par[n]=getpar(par[n]);
}
void lnk(int a,int b)
{
    a=getpar(a);
    b=getpar(b);
    if(a!=b)
    {
        if(rnk[a]>=rnk[b])
        {
            rnk[a]+=rnk[b];
            par[b]=a;
        }
        else
        {
            rnk[b]+=rnk[a];
            par[a]=b;
        }
    }
}
int main()
{
    int n,m,w;
    cin>>n>>m>>w;
    I(n);
    for(int i=1;i<=n;i++)
        cin>>W[i];
    for(int i=1;i<=n;i++)
        cin>>B[i];
    int fr,to;
    for(int i=0;i<m;i++)
    {
        cin>>fr>>to;
        lnk(fr,to);
    }

    for(int i=1;i<=n;i++)
    {
       int p=getpar(i);
        v[p].pb(i);
        sum[p]+=W[i];
        be[p]+=B[i];
    }

    for(int i=1;i<=n;i++)
    {
        if(sz(v[i])!=0)
            v1.pb(i);
    }
 clr(mem,-1);

  cout<< solve(0,w)<<endl;
}




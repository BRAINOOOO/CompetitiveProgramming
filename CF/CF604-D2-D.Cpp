/*
the idea is simply there is dependancy between the value for functions eg f(0) to be 0 it needs a certain value for x and its value 
depends on f(x) and so on except for zero bec it depends on it self and f(0) means x will be zero so it depends on f(0) and to be valid
f(x) must be zero or k bec k^2 % p == k iff p==2 and he said that p is odd prime so p will never be 2 so i will have only one choice
*/

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
#define     point                    complex<double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-5);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
ll k;
int p;
bool vis[1000009];
vector<vector<int> >v(1000009);
 ll m=1000000000+7;
void dfs(int n)
{
    vis[n]=1;
    for(int i=0;i<sz(v[n]);i++)
    {
        if(vis[v[n][i]])
            continue;
        dfs(v[n][i]);
    }
}
int main()
{
    cin>>p>>k;

     ll ans=1;

    if(k==1)
    {
       ans*=p;
    }
    vis[0]=1;
    for(int i=0;i<p;i++)
    {
        v[(k*i)%p].pb(i);
        v[i].pb((k*i)%p);
    }

   for(int i=0;i<p;i++)
   {
       if(vis[i])
        continue;
      dfs(i);
       ans=(ans*p)%m;
   }

  cout<<ans<<endl;
}

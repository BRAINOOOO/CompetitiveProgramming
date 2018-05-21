/*
just observe that the differences between taking any node as the capital and its child as a capital
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
int val,vis[200009],C[200009];
vector<vector<pair<int,int>> > v(200009);

void dfs(int n)
{

    vis[n]=1;

    for(int i=0;i<sz(v[n]);i++)
    {
        int no=v[n][i].first;
        int cost= v[n][i].second;
        if(vis[no])
            continue;
        val+=cost;
        dfs(no);

    }
}

void dfs2(int n)
{

    vis[n]=1;

    for(int i=0;i<sz(v[n]);i++)
    {
        int no=v[n][i].first;
        int cost= v[n][i].second;
        if(vis[no])
            continue;
        C[no]=C[n]+(cost==0? 1:-1);
        dfs2(no);

    }
}













int main()
{
    M();
    int n;
    cin>>n;
   int x,y;
    for(int i=1;i<=n-1;i++)
    {
        cin>>x>>y;
        v[x].pb(mp(y,0));
        v[y].pb(mp(x,1));
    }
   val=0;
   dfs(1);

   C[1]=val;
   clr(vis,0);
   dfs2(1);
   int mx=2000000;
   for(int i=1;i<=n;i++)
   {
       mx=min(C[i],mx);
   }

   cout<<mx<<endl;

   for(int i=1;i<=n;i++)
      if(C[i]==mx)
       cout<<i<<" ";
}

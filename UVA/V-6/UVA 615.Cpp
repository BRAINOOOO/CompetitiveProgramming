/*
explanation : here i know that the definiation of the tree is to have n nodes and n-1 edges but
and thats true but if you set this condition there is millions of cases that will fit in the condition
and it isnt a tree one of those cases is what if there is two separete nodes one of them have a self loop
and the other is without edges over all the count of edges is 1 and the count of nodes is 2 so it fits in
the condition :) , so you need to do dfs starting with the root and check for a cycle and the count of
nodes you visit.

complexity : O(E*log(n))
*/
#include <bits/stdc++.h>
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
const double eps= (1e-10);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int cnt,flag;
map< ll,ll> vis,mb;
map<ll,vector<ll> > v;
void dfs(ll id)
{
    if(vis[id])
    {
        flag=1;
        return ;
    }
    vis[id]=1;
    cnt++;
    for(int i=0;i<sz(v[id]);i++)
    {
        dfs(*(v[id].begin()+i));
    }
}
int main()
{
    int cs=1;
    while(1)
    {
         cnt=0;
        set<int> s;
        int fl=0;
         flag=0;
        int a,b;
        vis.clear();
        v.clear();
        mb.clear();
        while(1)
        {
            cin>>a>>b;
            if(a<0&&b<0)
            {
                fl=1;
                break;
            }
            if(a==0&&b==0)
                break;
          mb[b]=1;
          mb[a]=0;
          s.insert(a);
          s.insert(b);
          v[a].pb(b);
        }
        if(fl)
            break;
        ll A;
        for(auto i=mb.begin();i!=mb.end();i++)
        {
             if((*i).second==0)
            {
                 A=(*i).first;
                 break;
            }
        }
        dfs(A);
        if((cnt==sz(s)&&!flag)||(sz(s)==0))
             cout<<"Case "<<cs++<<" is a tree.\n";
        else
            cout<<"Case "<<cs++<<" is not a tree.\n";
    }
}

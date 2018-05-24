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
int k;
vector<int> v1,v2;
int vis[100009],tim[100009];
vector<vector<int> > v(100009);
void dfs(int id,int c)
{
   // cout<<id<<" "<<tim[id]<<endl;
    if(vis[id]==1&&c-tim[id]>=k+1)
    {
        v2=v1;
       // cout<<tim[id]<<endl;
        return;
    }
    if(vis[id]==1)
     return;

    vis[id]=1;



    for(int i=0;i<sz(v[id]);i++)
    {
        int no=v[id][i];
        v1.pb(no);
        if(tim[no]==0&&no!=1)
        tim[no]=c+1;
        dfs(no,c+1);

        v1.pop_back();
    }
}
/*
7
8
3
1 2
1 3
3 4
4 5
5 6
6 7
2 3
7 2
*/

int main()
{
    int n,m;
    cin>>n>>m>>k;
    int f,t;
    for(int i=0;i<m;i++)
    {
        cin>>f>>t;
        v[f].pb(t);
        v[t].pb(f);
    }
    v1.pb(1);
    dfs(1,0);
    v1.pop_back();

    int cnt=0;
    int NN=v2.back();
    v2.pop_back();
    int fl=0;
    stringstream ss;
    for(int i=0;i<sz(v2);i++)
    {
        if(v2[i]==NN)
            fl=1;
        if(fl)
            ss<<v2[i]<<" ",cnt++;
    }
    cout<<cnt<<endl<<ss.str()<<endl;
}

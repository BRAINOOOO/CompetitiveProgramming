/*
if you think that the dp solution is TLE it is not bec we won't use  all the -100000 - 100000 range here is the key :) .
*/


// ICPC Champion is here

//#include <bits/stdc++.h>
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
//int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
map< pair<int,int>,int > mem;
pair<int,int> v[100009];
int N;
int solve(int ro,int cl)
{
    if(mem.find(mp(ro,cl))!=mem.end())
        return mem[mp(ro,cl)];

    int ncl=v[ro].first;
    int nncl=v[ro].second;
    int fl=0,fl2=0,p1,p2;
    for(int i=ro+1;i<=N&&(!fl||!fl2);i++)
    {
        if(ncl>=v[i].first&&ncl<=v[i].second&&!fl)
        {
            p1= cl-ncl+solve(i,ncl);
            fl=1;
        }
        if(nncl>=v[i].first&&nncl<=v[i].second&&!fl2)
        {
            p2= nncl-cl+solve(i,nncl);
            fl2=1;
        }
    }

    if(!fl)
    {
        p1= cl-v[ro].first+abs(v[ro].first);

    }
    if(!fl2)
    {
        p2= v[ro].second-cl+abs(v[ro].second);
    }

    return mem[mp(ro,cl)]=min(p1,p2);
}









int main()
{
    int S;
    scanf("%d %d",&N,&S);
    int id=2;
    int x1,x2;
    for(int i=1;i<=N;i++)
    {
        scanf("%d %d",&x1,&x2);
        v[N-i+1]=mp(x1,x2);

    }


      printf("%d\n", solve(1,S));
}


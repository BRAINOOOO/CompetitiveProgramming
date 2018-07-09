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
#define     point                    complex<double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-5);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
double p[209],mem[209][609][209];
int l,n,k,res[209];
int shft=200;

double solve(int id,int cap,int pz)
{
    if(id==n)
    {
        if(pz>=l&&cap>=0)
            return 1.0;
        return 0.0;
    }


    double &ret=mem[id][cap+shft][pz];

    if(ret==ret)
        return ret;
    double ans=0.0;
    if(res[id]==-1)
    ans+= p[id]*solve(id+1,cap-1,pz+1);
    else
    {
        int re= (cap+res[id] >200? 200 : cap+res[id]);
        ans+= p[id]*solve(id+1,re,pz+1);
    }

    ans+= (1-p[id])*solve(id+1,cap,pz);

 return ret=ans;
}








int main()
{
    cin>>n>>l>>k;

    for(int i=0;i<n;i++)
    {
       cin>> p[i];
       p[i]/=100;
    }

    for(int i=0;i<n;i++)
        cin>>res[i];
    clr(mem,-1);
   cout<<fixed<<setprecision(6)<< solve(0,k,0)<<endl;
}





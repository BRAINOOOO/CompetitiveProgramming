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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}

int n,a,b,t,v[500009],T;
string st;
ll mx=0;

bool check(int val,int rg)
{
     ll p1,p2,p3;
// 3,4

    p1= (v[val]-v[0])*b+val+(val)*a;

    p3= min(val,rg)*a;

   ll cost=p1+p3;
 //cout<<p1<<" "<<p2<<" "<<p3<<endl;
   if(cost<=t)
    return 1;
   return 0;
}










void BS(int val,int rg)
{

    int l=1;
    int r=(val==0? n-1:val-1);
    int ans=0;
//cout<<l<<" "<<r<<endl;
    while(l<=r)
    {

        int mid=(l+r)/2;

        if(check(mid,rg))
            l=mid+1,ans=mid;
        else
            r=mid-1;

    }

    ll res= (ans)+rg+1;
  //  if(res==5)
       // cout<<val<<" "<<ans<<endl;
    mx=max(mx,res);
}














int main()
{

    cin>>n>>a>>b>>T>>st;

    for(int i=0;i<n;i++)
    {

        v[i]=(i-1>=0?v[i-1]:0)+(st[i]=='w'?1:0);

    }

    for(int i=0;i>=-(n-1);i--)
    {

        int l=(i<0?i+n:0),lim,rg;
         t=T;
        if(l==0)
            lim=v[0],rg=1;
        else
            lim=v[n-1]-v[l-1]+v[0],rg=n-1-l+2;

        if(lim*b+rg+(rg-1)*a>t)
        continue;

        t-=lim*b+rg+(rg-1)*a;

        BS(l,rg-1);
    }
  //cout<<check(1,3)<<endl;
   cout<<mx<<endl;
}









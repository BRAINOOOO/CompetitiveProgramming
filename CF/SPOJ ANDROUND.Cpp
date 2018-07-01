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
ll n,k,tree[(1<<16)+9],arr[20009];

ll build(int s=0,int e=n-1,int p=1)
{

    if(s==e)
    {
        return tree[p]=arr[s];

    }

    int mid=(s+e)>>1;

  return tree[p]= build(s,mid,p*2)&build(mid+1,e,p*2+1);
}

ll query(int a,int b,int s=0,int e=n-1,int p=1)
{

    if(s>b||e<a)
        return (1ll<<35)-1;


    if(s>=a&&e<=b)
    {
        return tree[p];
    }

    int mid=(s+e)>>1;

   return query(a,b,s,mid,p*2)&query(a,b,mid+1,e,p*2+1);
}


ll power(ll b,ll p)
{
    if(p<=0)
        return 1ll;

    if(p&1)
        return (b*power(b*b,p/2))%n;
    else
        return power(b*b,p/2)%n;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

    cin>>n>>k;

    for(int i=0;i<n;i++)
        cin>>arr[i];

    build();
    ll ans,p;

    ll range= min(2*(k-1)+3,n);
    k=min(k,n);


    for(int i=0;i<n;i++)
    {

        ll st= ((i-k)+n)%n;
        ll en= ((st+range-1)+n)%n;

         if(st<n&&en<n&&st<=en)
           ans= query(st,en);
         else
         {
             ans= query(st,n-1)&query(0,en);
         }


        st=(st+1)%n;
        en=(en+1)%n;

        cout<<ans<<" ";
    }
    cout<<endl;
    }
}

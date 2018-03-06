/*
explanation : i will suppose a certain min about after k operations and check using binary search and the same for max value the idea is 
as simple as that.

complexity : nlog(c)
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
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1ll;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
vector< ll > v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int no;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        v.pb(no);
    }
    ll l=0;
    ll h=2000000000;
    ll res;
    while(l<=h)
    {

        ll mid=(l+h)/2;
        ll s=0;
        for(int i=0;i<n;i++)
        {
            s+=max(0ll,mid-v[i]);
        }

        if(s<=k)
            l=mid+1,res=mid;
        else
            h=mid-1;
    }
     int tk=k;
     for(int i=0;i<n;i++)
     {
         tk-=max(0ll,res-v[i]);
         v[i]=max(v[i],res);
     }

     for(int i=0;i<n;i++)
     {
         if(v[i]==res&&tk)
            v[i]++,tk--;
     }
     l=0;
     h=2000000000;
      while(l<=h)
    {
        ll mid=(l+h)/2;
        ll s=0;
        for(int i=0;i<n;i++)
        {
            s+=max(0ll,v[i]-mid);
        }
        if(s<=k)
            h=mid-1,res=mid;
        else
            l=mid+1;
    }
      tk=k;
     for(int i=0;i<n;i++)
     {
         tk-=max(0ll,v[i]-res);
         v[i]=min(v[i],res);
     }
     for(int i=0;i<n;i++)
     {
         if(v[i]==res&&tk)
            v[i]--,tk--;
     }
   cout<< (*max_element(all(v)))-(*min_element(all(v))) <<endl;
}

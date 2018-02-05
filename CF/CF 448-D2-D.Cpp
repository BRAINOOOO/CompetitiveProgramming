/*
explanation : here the idea is the multiplication table of any number is sorted right so i can get the number of elements in the 
table less than a certain number by iterating on the rows and calcualte for each row ( multiplication table whats the number of numbers 
less than even number and sum up ) then i will binary search on the answer if the numbers less mid are equal or more than k to the result
should be less than this number so i will go back :) 

complexity ; O( nlogn ).
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
ll m,n,k;
bool calc(ll no)
{
    ll ans=0;
    for(int i=1;i<=min(n,no);i++)
    {
       ll s=ceil((no+0.0)/i);
        if(s<=m)
        ans+=  s-1;
        else
            ans+=m;
    }
    if(ans>=k)
        return 1;
    return 0;
}
int main()
{
    cin>>n>>m>>k;
    ll l=1;
    ll  h=n*m;
    ll mid,ans;
    while(l<=h)
    {
         mid=(l+h)/2;
        if(!calc(mid))
            l=mid+1,ans=mid;
        else
           h=mid-1;
    }
      cout<<ans<<endl;
}

/*
exolanation : its obvious that the idea is recursively it is like sub problems to make sure the big problem is right you should go to
sub problems from it .
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
int fun(string s1,string s2)
{

    if(s1==s2)
    return 1;
   if(sz(s1)%2!=0)
   return 0;
    string s1p1= s1.substr(0,sz(s1)/2);
    string s1p2= s1.substr(sz(s1)/2,sz(s1)/2);
    string s2p1= s2.substr(0,sz(s2)/2);
    string s2p2= s2.substr(sz(s2)/2,sz(s2)/2);
    if((fun(s1p1,s2p2)&&fun(s1p2,s2p1)))
        return 1;
    if(fun(s1p1,s2p1)&&fun(s1p2,s2p2))
        return 1;
    
        return 0;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(sz(s1)%2!=0)
    {
        if(s1==s2)
            cout<<"YES\n";
        else
           cout<<"NO\n";
        return 0;
    }
   if( fun(s1,s2))
    cout<<"YES\n";
   else
    cout<<"NO\n";
}

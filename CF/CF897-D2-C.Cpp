/*
explanation : here lets divide the f(n) to 5 divisions s1+ f(n-1) + s2 + f(n-1) + s3
we can easily determine the k lies in which division if its at s1 or s2 or s3 return sX[k]
but if it lies in f(n-1) we will go recursively to f(n-1) and do the same, but to know
whether k lies in f(n-1) or not okay its obvious that f(n) greater than f(n-1) by f(n-1)+s1+s2+s3
so i will calculate the length of f(i) till f(i) reaches the max K according to constrains and if i
exceeds this limit so it will surely lie in s1 or the first f(n-1).

complexity : smaller than Q*N
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
const ll MAX=1000000000000000000;
string f0="What are you doing at the end of the world? Are you busy? Will you save us?";
string first="What are you doing while sending \"";
string sec="\"? Are you busy? Will you send \"";
string third="\"?";
ll len[100+9],i;
char  fun(int n,ll k)
{
    if(!n)
    {
        if(k<=sz(f0))
            return f0[k-1];
        return '.';
    }
    if(k<=sz(first))
        return first[k-1];
    k-=sz(first);
    if(n>=i||k<=len[n-1])
        return fun(n-1,k);
    k-=len[n-1];
    if(k<=sz(sec))
        return sec[k-1];
    k-=sz(sec);
       if(n>=i||k<=len[n-1])
        return fun(n-1,k);
    k-=len[n-1];
       if(k<=sz(third))
        return third[k-1];
    return '.';
}
int main()
{
    int q;
    cin>>q;
    len[0]=sz(f0);
    for( i=1;len[i-1]<=MAX;i++)
    {
        len[i]= 2*len[i-1]+sz(first)+sz(sec)+sz(third);
    }
   ll n,k;
    while(q--)
    {
        cin>>n>>k;
        cout<<fun(n,k);
    }
}

/*
explanation : here it is easy to observe that if i take k common factor from all the elements in a set so their gcd will be equal to 
one now the problem is how i can get the elements that their gcd equals to 1 and of min m okay 

    it is obvious that in a set there couldn't be two even numbers so there must be 3 odd numbers 
    1 2 3 5 okay for the first set with min m now in the second set why it is optimal to start with the even element and it is 6
    and it looks like 6 7 9 11  okay its not true bec 6 and 9 are divisile by 3 and to avoid that let it be 6 7 11 13 its true but the
    min here is m is 13 okay but if i escaped 6 it will look like 7 8 9 11 where m is smaller here, if you still can't understand 
    just simulate by your hand :)
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tupl
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
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<(6*n-1)*k<<endl;
    int a=0;
    for(int i=0;i<n;i++)
    {
           cout<<(6*a+1)*k<<" "<<(6*a+2)*k<<" "<<(6*a+3)*k<<" "<<(6*a+5)*k<<endl;
            a++;
    }
}

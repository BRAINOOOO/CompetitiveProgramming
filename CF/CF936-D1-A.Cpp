/*
explanation : here the idea is if k % d ==0 this means that when it is off directly you will turn it on again so it will never be off
so you will take t else so you will calculate the difference the chiken spend on oFF state which is diff variable , realize that it will
be a cycle ON then OFF for diff mins then ON and so on...
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
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}

int main()
{
    ll k,d,t;
    cin>>k>>d>>t;

    if(k%d==0)
    {
        cout<<t<<endl;
        return 0;
    }
    ll diff= d*(k/d+1)-k;

    double b= diff/(2*t+0.0);
    double a=k/(t+0.0);

    ll mn=diff+k;

    double s=a+b;
    ll cycle= 1/s;

    double fl= 1/s;

    double tot=mn*cycle;
    double w=fl-cycle;
    double e=w*s;
    if(e<=a)
        tot+=e*t;
    else
    {

        tot+= k;
        e-=a;
        tot+= e*2*t;
    }
    cout<<fixed<<setprecision(13)<<tot<<endl;
}

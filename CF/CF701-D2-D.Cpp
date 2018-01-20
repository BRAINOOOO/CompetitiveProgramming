/*
explanation : if t is the value you are using in binary search:
# since all people uses the bus for the same amount of time, I can calulate this time:
let tbus be time used by bus for each group
let twalking be time used by walking for each group

we have those 2 equations (1) and (2):
(1) v1*twalking + v2*tbus = dist
(2) twalking + tbus = t		(multiplying both sides by -v1)
-v1*twalking -v1*tbus = -v1*t 	(summing this equation with (1))

(v2-v1) * tbus = dist - v1*t

tbus = (dist - v1*t) / (v2-v1)

# now observe that each group each time, the bus and people at same position at beginning (0), bus takes a group, rides for tbus seconds, then get back at them to take other group, and so on, so since the time the bus takes for each group is the constant (same), the time used by the bus to go backwards to get each group is also the constant (same), so we are going to calculate it:
let's call the distance between people and bus at the moment which bus turn around to get closer again to the people by gap distance 
gap distance = distance used by bus - distance used by people = v2*tbus - v1*tbus = (v2-v1)*tbus
let's call the time used by bus to go backwards to get other group by tpickup
tpickup = gap distance / (v1+v2) 	[to understand it, imagine that velocity is the sum of both as one is going closer by v1 and other is getting closer by v2, so they are getting closer to each other by velocity v1+v2, also time is distance/velocity]

total time = time of bus going forward + time of bus going backwards = tbus * groups_number + tpickup * (groups_number - 1)

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
int n,d,v1,v2,k;
bool f(double tar)
{
    double tbus= 1.0*(d-v1*tar)/(v2-v1);
    if(tbus<=0.0)
        return true;
    double gp=ceil(1.0*n/k);
    double dist= (v2-v1)*tbus;
    double bak=dist/(v2+v1);
    if(bak*(gp-1)+tbus*gp < tar)
        return true;
    return false;
}
int main()
{
    cin>>n>>d>>v1>>v2>>k;
   int L=300;
    double l=0.0,h=1e9,mid;
    while(L--)
    {
        mid=(l+h)/2.0;
        if(f(mid))
            h=mid;
        else
            l=mid;
    }
    cout<<fixed<< setprecision(12)<<mid<<endl;
}

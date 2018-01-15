/*
first of all you have observe that y must be divisable by x first then 
i want sum=y and gcd=x so in other words i can say that i need sum=y/x with gcd=1
the number of ways to get sum = t let it be g(t) = 2^(t-1) ( see stars and bars theorm ) 
but i need it with gcd =1 okay let f(t) be the number of ways to make sum=t with gcd =1
         i=size
g(t)= sigma      f(t/ti)  where ti is the ith divisor of t .
          i=1

i want f(t) where t=y/x

            i=size                i=size
 f(t)=    sigma      f(t/ti) -   sigma   f(t/ti)  
             i=1                    i=2
         --------------------
                  |
                  |
                  |
                2^(t-1)
                
 so the recurance will be
                         i=size
        f(t) = 2^(t-1) -   sigma  f(t/ti)
                         i=2
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
map<ll,ll> mb;
const ll M=1000000007;
ll power(ll b,ll p)
{
    if(p==0)
        return 1ll;
    if(p&1)
        return ((b%M)*(power((b*b)%M,p/2)%M))%M;
    else
        return (power((b*b)%M,p/2)%M)%M;
}

ll solve(ll sum)
{
    if(sum==1)
        return 1ll;
    if(mb.find(sum)!=mb.end())
        return mb[sum];
    ll ret=((power(2,sum-1)-1)+M)%M;
    int i;
    for(i=2;i*i<sum;i++)
    {
        if(sum%i==0)
        {
            ret=  (ret- (solve(sum/i)+solve(i))+M)%M;
        }
    }
    if(i*i==sum)
        ret=(ret-solve(i)+M)%M;

   mb[sum]=ret;
    return ret;
}
int main()
{
   int y,x;
    cin>>x>>y;
    if(y%x!=0)
    {
        cout<<"0";
        return 0;
    }
    cout<<solve(y/x)<<endl;
}

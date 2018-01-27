/*
explanation : here the idea is if pair of integers have an lcm n so they must of divisors of n but it is not necessary that they have 
lcm equal to n as they might have common multiple less than n so i will work with the first observation and also bec of the second 
observation i will check pairwise in n^2 that their lcm equal to n.
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
vector<int > v;
void divisors(int n)
{
    int i;
    for( i=1;i*i<n;i++)
    {
        if(n%i==0)
        {
            v.pb(i);
            v.pb(n/i);
        }
    }
    if(i*i==n)
        v.pb(i);
}
int main()
{
    int n;
    while(cin>>n)
    {
           if(n==0)
            break;
        v.clear();
        divisors(n);
        int cnt=0;
        for(int i=0;i<sz(v);i++)
        {
            for(int j=i+1;j<sz(v);j++)
            {
                ll a=v[i];
                ll b=v[j];
               ll l=lcm(a,b);
                if(l==n)
                    cnt++;
            }
        }
        cnt++;
       cout<<n<<" "<<cnt<<endl;
    }
}

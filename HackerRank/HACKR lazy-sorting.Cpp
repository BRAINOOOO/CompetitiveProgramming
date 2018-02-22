/*
explanation : here the idea is the same as geometric distribution of discrete random variables but here if i take x mins till i get it
sorted the operation the E(X)= sigma (1-p)^x * p *x which is equal tp (1-p)/p  want the proof follow this link till subtitle 
"Moments and cumulants"  link -----> https://en.wikipedia.org/wiki/Geometric_distribution , where p is the probability of getting it
sorted in the current shuffle which is 1/S where S is the sample space which is all the permutations of the array but takecare
of repitions.
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
vector<int> v;
int vis[1009];
double f(int n)
{
    double s=1.0;
    for(int i=2;i<=n;i++)
        s*=i;
    return s;
}
int main()
{
    int n;
    cin>>n;
    int no;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        v.pb(no);
        vis[no]++;
    }
    vector<int> tv;
    tv=v;
    sort(all(tv));
    if(tv==v)
    {
        cout<<"0.000000";
        return 0;
    }
    double S=f(n);
    tv.erase(unique(all(tv)),tv.end());
    for(int i=0;i<sz(tv);i++)
    {
       ll c=vis[tv[i]];
        S/=(f(c));
    }
    cout<<fixed<<setprecision(6)<<S<<endl;
}

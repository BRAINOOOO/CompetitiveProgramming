/*
explanation : lets divide the problem in to two partions the first one is suppose i have the permutation that have the max expectation 
now how i can get the expectation of it okay, first i will listen to all the songs with probability 100% right okay and each ith song
i will listen to it again which adds to the cost l[i] will be with probability that sigma p[j] where j>i mulitiplied by p[i] so you
can calculated, in other words   
                                 cost= sum+ extra       where sum is the sum of all the songs time and extra is the extra time i may
                                                        gained by returning to some songs and listen to them again 
 and by linearity of expectation so
                               
                                E( cost )= E( sum )+ E( extra )
                              = E( cost )= sum + E( extra )
                 
                 and E( extra ) = probability that you will get the value from the ith song * l[i] *( sigma probability of dislike for 
                                                                                                        jth song where j>i).
                                                                                                        
 Now  the second part how i will decide the optimal permuation it explained in a good way at editorial ---> 
 http://codeforces.com/blog/entry/6545?locale=en
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
vector< pair<int,double> > v;
bool cmp(pair<int,double> p1,pair<int,double> p2)
{
    return p1.first*p1.second*(1-p2.second) > p2.first*p2.second*(1-p1.second);
}
int main()
{
    int n;
    cin>>n;
    int l;
    double p;
    for(int i=0;i<n;i++)
    {
        cin>>l>>p;
        p/=100;
        v.pb(mp(l,p));
    }
    sort(all(v),cmp);
    double ans=0.0,rat=0.0;
    for(int i=0;i<n;i++)
    {
        ans+= v[i].first;
        ans+= rat* (1-v[i].second);
        rat+= v[i].second*v[i].first;
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

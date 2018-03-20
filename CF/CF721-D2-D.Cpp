/*
explanation : the idea is my periority is to make the product -ve with min operations then increasing the product if i can't so 
my next periority is to make the product equals to zero if i can't so i have to minmize the product.
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
vector<ll> v;
int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    int no,t=1;
    priority_queue<pair<ll,ll>> pq;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        v.pb(no);
        pq.push(mp(-abs(no),i));
        if(no<0)
        t*=-1;
    }
    int s;
    while(k--)
    {
        s=t;

        int id=pq.top().second;
        pq.pop();

        if(v[id]<0)
            s*=-1;

        if(s==1)
            v[id]-=x;
        else
            v[id]+=x;

        t=s;

        if(v[id]<0)
            t*=-1;


        pq.push(mp(-abs(v[id]),id));
    }

    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
}

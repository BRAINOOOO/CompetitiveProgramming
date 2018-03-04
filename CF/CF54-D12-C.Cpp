/*
explanation : here i first calculate the probability of each position to have first digit one according to its range then do dp
and if the number of ones you choosed which i express it as cnt is K% or more from n so its good sequence and consider it else don't
consider it.

complexity : O( n^2 )
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
vector< pair<ll,ll> > v;
double p[1009],mem[1009][1009];
int n;
double k;
double solve(int id,int cnt)
{
    if(id==n)
    {
        if(dcmp((cnt/(n+0.0)),k)!=-1)
        {
            return 1;
        }
        return 0;
    }
    if(mem[id][cnt]!=-1)
        return mem[id][cnt];
    double ans=0.0;
    ans+= p[id]*solve(id+1,cnt+1);
    ans+= (1-p[id])*solve(id+1,cnt);
    mem[id][cnt]=ans;
    return ans;
}
int main()
{
    v.pb(mp(1,1));
    string s1="1",s2="1";
    for(int i=1;i<=18;i++)
    {
        s1+='0';
        s2+='9';
        ll n1=atoll(s1.c_str());
        ll n2=atoll(s2.c_str());
        v.pb(mp(n1,n2));
    }
    cin>>n;
    ll L,R;
    for(int i=0;i<n;i++)
    {
        cin>>L>>R;
        ll rs=0;
        for(int j=0;j<sz(v);j++)
        {
            ll a=v[j].first;
            ll b=v[j].second;

            if(a<=L&&R<=b)
                rs+=R-L+1;
            else if(L<=a&&b<=R)
                rs+=b-a+1;
            else if(a<=R&&a>=L)
                rs+=R-a+1;
            else if(b<=R&&b>=L)
                rs+=b-L+1;
        }
        p[i]=(rs/((R-L+1)+0.0));
    }
    cin>>k;
    k/=100;
    for(int i=0;i<1009;i++)
        for(int j=0;j<1009;j++)
          mem[i][j]=-1;

    cout<<fixed<<setprecision(9)<<solve(0,0);
}

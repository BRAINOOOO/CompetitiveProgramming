/*
first of all yu will realize that there is a cycle so simply rearrange the recurrance 
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
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
double mem[101][101][101];
double solve(int r,int p,int s)
{
    double &ret=mem[r][p][s];
    if(ret==ret)
        return ret;
    if(p==0&&s==0)
        return ret=1;
    if(r<=0)
        return ret=0;
    if(p<0||s<0)
        return ret=0;

    double N= s*s+s*p+s*r+p*p+p*r+r*r;

    double Nemo= -(r*p)/N*solve(r-1,p,s) - (p*s)/N*solve(r,p-1,s) - (r*s)/N*solve(r,p,s-1);
    double Demo= (r*r)/N+ (p*p)/N + (s*s)/N-1;

    double res;
    if(Demo!=0)
    res = Nemo/Demo ;
    else
     res=Nemo;

    return ret=res;
}

int main()
{
    int r,p,s;

    cin>>r>>s>>p;
    clr(mem,-1);
    cout<<fixed<<setprecision(10)<<solve(r,p,s);
    clr(mem,-1);
    cout<<" "<<solve(s,r,p);
    clr(mem,-1);
    cout<<" "<<solve(p,s,r)<<endl;
}

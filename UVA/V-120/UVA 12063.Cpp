/*
explanation : here the idea is imagin a normal recursion to get all the permuatations of zeros and ones 
what is different here is that i want to express this binary as a number and check its divisibility
by k so i decide to work with masks to get the number easily and mod it.

complexity : ( n^2 )/4 * K *T
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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
ll n,k;
ll mem[64+9][35+9][101+9];
ll fun(ll z,ll one,ll mod)
{
    if((z>n/2)||(one>n/2))
        return 0;
        if(z+one==n)
        {
           if((z==one) && (mod==0))
            return 1;
            return 0;
        }
    if(mem[z][one][mod]!=-1)
        return mem[z][one][mod];
    ll ans=0;
    ans+= fun(z,one+1, ((mod<<1)+1)%k);
    ans+= fun(z+1,one,(mod<<1)%k);
    mem[z][one][mod]=ans;
    return ans;
}
int main()
{
    int cs;
    cin>>cs;
    for(int i=1;i<=cs;i++)
    {
    cin>>n>>k;
    cout<<"Case "<<i<<": ";
     if(k==0)
    {
      cout<<"0\n";
      continue;
    }
    clr(mem,-1);
    cout<< fun(0,1,1%k) <<endl;

    }
}
